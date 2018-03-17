#字符串和因子
c("Ask the indulgence of the children who may read this book for dedicating
  it for a grown-up.","I would bring myself down to his level.")
paste(c("red","blue"),"lorry")
paste(c("red","blue"),"lorry",sep = "+")
paste(c("red","blue"),"lorry",collapse =".")
paste0(c("red","blue"),"lorry")#pasete0去掉分隔符
xx <- (1:15)^2
toString(xx)
toString(xx,width = 40)
cat(c("red","yellow"),"lorry")
x1 <- c("I","have","see","them","intimately","close","at","hand")
y <- noquote(x1)
y
pow <- 1:3
(pow_of_e <- exp(pow))
formatC(pow_of_e)
formatC(pow_of_e,digits = 3)
formatC(pow_of_e,digits = 3,width = 10)#前面补齐空格
formatC(pow_of_e,digits = 3,format = "e")#科学计数法
formatC(pow_of_e,digits = 3,flag = "+")#前面加上+

sprintf("%s %d = %f","Euler's constant to the power",pow,pow_of_e)
sprintf("To three decimal places, e ^ %d = %.3f", pow, pow_of_e)
#较短长度的输入将循环自身以匹配最长的输入

#format()类似于formatC()
format(pow_of_e,digits = 3,trim = TRUE)#去掉多余的0
format(pow_of_e,digits = 3,scientific = TRUE)#科学计数法
#格式化特殊字符
prettyNum(
  c(1e10,1e-20),
  big.mark = ",",#大数字用逗号进行分割
  small.mark = "",#小数字去掉分隔符
  preserve.width = "individual",
  scientific = FALSE #非科学计数法
)

#\t制表符
cat("foo\tbar",fill = TRUE)# cat的参数fill = TRUE使光标在一行结束后移动到下一行
foo	bar
#\n将光标移动到下一行
cat("foo\nbar",fill = TRUE)
#\r将光标移动到下一行
cat("foo\rbar",fill = TRUE)#\r会将光标移动到当前行的开始并覆盖你所写的内容
cat("foo\0bar", fill = TRUE) #这会抛出一个错误
cat("foo\\bar", fill = TRUE)
#单双引号需要被转义
cat("foo\"bar", fill = TRUE)
cat('foo\'bar', fill = TRUE)
#单双引号混合用无需转义
cat("foo'bar", fill = TRUE)
#警报函数
cat("\a")
alarm()
toupper("I'm shy")
tolower("ECHO")

little_prince <- c(
  "Boa constrictors swallow their pre whole",
  "they sleep through six, months that for digestion ",
  "I gave up what might have been a magnificent career as a painter"
)
substring(little_prince,1:3,10)
substr(little_prince,1:3,10)

strsplit(little_prince," ,?")#返回列表
strsplit(little_prince,",?")#执行试试

#工作目录，默认为文件被读写的地方
getwd()
setwd("c:/")#文件处理函数能够魔术般地把它们自动替换为反斜杠
getwd()
setwd("D:/Documents")

file.path("c:","Program Files","R","R-devel")
R.home() #同样也是R的安装目录
path.expand("~")
file_name <- "C:/Program Files/R/R-devel/bin/x64/RGui.exe"
basename(file_name)
dirname(file_name)

#因子
(heights <- data.frame( 
     height_cm = c(153, 181, 150, 172, 165, 149, 174, 169, 198, 163), 
     gender = c(
         "female", "male", "female", "male", "male",
         "female", "female", "male", "male", "female"
       )
     )
)

class(heights$gender)
class(heights$height_cm)
heights$gender[1] <- "Female"
levels(heights$gender)#因子水平
nlevels(heights$gender)#水平级数

gender_char <- c(
    "female", "male", "female", "male", "male",
    "female", "female", "male", "male", "female" 
   )
(gender_fac <- factor(gender_char))#使用factor函数创建它。它的第一个参数（唯一的强制要求）是一个字符向量

factor(gender_char, levels = c("male", "female"))
relevel(gender_fac, "male")#改变因子水平顺序

getting_to_work <- data.frame(
     mode = c(
         "bike", "car", "bus", "car", "walk",
         "bike", "car", "bike", "car", "car"
       ),
     time_mins = c(25, 13, NA, 22, 65, 28, 15, 24, NA, 14) 
   )
getting_to_work
(getting_to_work <- subset(getting_to_work, !is.na(time_mins)))
unique(getting_to_work$mode)#类似于levels()
getting_to_work <- droplevels(getting_to_work)#droplevels函数将丢弃输入因子中所有未使用的水平

#有序因子
happy_choices <- c("depressed","grumpy",  "so-so", "cheery", "ecstatic") 
 happy_values <- sample(
    happy_choices,
     10000,
     replace = TRUE 
  ) 
happy_fac <- factor(happy_values, happy_choices) 
head(happy_fac)

happy_ord <- ordered(happy_values, happy_choices) 
head(happy_ord)
is.factor(happy_ord)
is.ordered(happy_fac)

ages <- 16 + 50 * rbeta(10000, 2, 3)
grouped_ages <- cut(ages, seq.int(16, 66, 10))#cut函数分组
head(grouped_ages)
table(grouped_ages)
class(ages)
class(grouped_ages)

#类别变量转换为连续变量
dirty <- data.frame(
  x = c("1.23", "4..56", "7.89") 
)
class(dirty$x)
type(dirty$x)
as.numeric(dirty$x)
as.numeric(as.character(dirty$x))
as.numeric(levels(dirty$x))[as.integer(dirty$x)]
factor_to_numeric <- function(f) 
   {
       as.numeric(levels(f))[as.integer(f)] 
     }
factor_to_numeric(dirty$x)

#生成因子水平
gl(3, 2)
gl(3, 2, labels = c("placebo", "drug A", "drug B"))
treatment <- gl(3, 1, 6, labels = c("placebo", "drug A", "drug B")) #交替

gender <- gl(2, 1, 6, labels = c("female", "male")) 
interaction(treatment, gender)


#Ch7
#7.6
#7-1  formatC()  format()  prettyNum() 
#7-2  alarm()  cat("\a")
#7-3  因子变量 factor
#7-4  报错
#7-5  num <- factor(num) 

#exercise
formatC(pi,digits = 16)

x <- c( 
  "Swan swam over the pond, Swim swan swim!",
  "Swan swam back again - Well swum swan!"
)
x <- gsub(pattern = "!|-|,",replacement = "",x)
strsplit(x," ")


three_d6 <- function(n)
{
  random_numbers <- matrix(
    sample(6, 3 * n, replace = TRUE)
    , nrow = 3
  )
  colSums(random_numbers) 
}
three_d6(3)
?sample()
#得分　奖励3-34,5-26~８-19~12013~15+116, 17+218+3，这是什么意思。。。
grade <- data.frame(c(1:1000),three_d6(1000))
head(grade)
grade[order(grade[,2]),]
