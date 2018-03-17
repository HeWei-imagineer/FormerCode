#ch9
rep(runif(1),5)
replicate(5,runif(1))

time_for_commute <- function()
{
  mode_of_trainsport <- sample(c("car","bus","train","bike"),
                               size = 1,
                               prob = c(0.1,0.2,0.3,0.4)
                               )
  time <- switch(
    mode_of_trainsport,
    car = rlnorm(1,log(30),0.5),
    bus = rlnorm(1,log(40),0.5),
    train = rnorm(1,30,0.5),
    bike = rnorm(1,60,0.5)
  )
  names(time) <- mode_of_trainsport
  time
}

replicate(5,time_for_commute())

prime_factors <- list(
     two = 2,
     three = 3,
     four = c(2,  2),
     five = 5,
     si = c(2,   3),
     evexn = 7,
    eisght = c(2,  2,  2),
     nine = c(3,  3),
      ten = c(2,  5)
   )
unique_primes <- vector("list", length(prime_factors))
for(i in seq_along(prime_factors)) 
   {
       message(i)
     
       unique_primes[[i]] <- unique(prime_factors[[i]])#???
       message( "pre", unique_primes[[i]] )
       message( "after", prime_factors[[i]])
   }
names(unique_primes) <- names(prime_factors) 
unique_primes

lapply(prime_factors, unique)
vapply(prime_factors, length, numeric(1))

sapply(prime_factors, length)#返回一个向量
sapply(prime_factors, summary)#返回一个数组
sapply(list(), length)#有时返回向量，有时返回列表
vapply(list(), length, numeric(1))#需传入返回值模板

install.packages("matlab")
library(matlab)
#detach("package:matlab")恢复初始设置
magic4 <- magic(4)
magic4
rowSums(magic4)
apply(magic4,1,sum)
apply(magic4,1,toString)
apply(magic4,2,toString)

 (baldwins <- data.frame(
     name = c("Alec", "Daniel", "Billy", "Stephen"),
    date_of_birth = c(
         "1958-Apr-03", "1960-Oct-05", "1963-Feb-21", "1966-May-12"
       ),
     n_spouses = c(2, 3, 1, 1),
     n_children = c(1, 5, 3, 2),
     stringsAsFactors = FALSE 
   ))

apply(baldwins,2,toString)
sapply(baldwins, toString)
#sapply与range结合使用能非常迅速地确定你的数据范围：
sapply(baldwins, range)

#mapply多传一个参数做名字
msg <- function(name, factors) 
{
  ifelse(
    length(factors) == 1,
    paste(name, "is prime"),
    paste(name, "has factors", toString(factors))
  ) 
} 
mapply(msg, names(prime_factors), prime_factors)

#传递参数SIMPLIFY =  FALSE，使输出结果类似lapply
mapply(msg, names(prime_factors), prime_factors,SIMPLIFY =  FALSE)

baby_gender_report <- function(gender) 
{
  switch(
    gender,
    male = "It's a boy!",
    female = "It's a girl!",
    "Um..."
  ) 
}
#Vectorize是mapply的包装函数。通常它接受一个标量作为输入参数，并返回一个新的接受向量的函数。
#向量化函数，使输入为标量的函数可以多次运用于一个一个向量的每个值
genders <- c("male", "female", "other")
baby_gender_report(genders)
vectorized_baby_gender_report <- Vectorize(baby_gender_report)
vectorized_baby_gender_report(genders)

(frogger_scores <- data.frame(
     player = rep(c("Tom", "Dick", "Harry"), times = c(2, 5, 3)),
     score = round(rlnorm(10, 8), -1)
   ))

#1，把数据分成不同小组
(scores_by_player <- with(
     frogger_scores,
     split(score,player)
   ))
#2，计算每个小组平均值
(list_of_means_by_player <- lapply(scores_by_player, mean))

#3、我们把结果合并到单个向量中：
(mean_by_player <- unlist(list_of_means_by_player))

#以上步骤可直接用tapply一步完成
with(frogger_scores, tapply(score, player, mean))

install.packages("plyr")
library(plyr)
llply(prime_factors, unique)
laply(prime_factors,length)
laply(list(),length)
raply(5,runif(1))#数组输出
rdply(5,runif(1))#数据框输出
r_ply(5,runif(1))#丢弃输出

frogger_scores$level <- floor(log(frogger_scores$score))
ddply(
     frogger_scores,
     .(player),
     colwise(mean) # 除了player之外，对每个列调用mean函数
)

ddply(
    frogger_scores,
     .(player),
     summarize,
     mean_score = mean(score), # 对score调用mean
     max_level = max(level)    #... 然后求level的max值
   )


#9-1 lapply vapply sapply apply maplly taplly
#9-2 返回列表，参数为：列表，函数；把结果化简为向量或数组，参数为：列表，函数，返回值模板；同vapply,但会化简结果
#9-3  使用sapply（列表，函数）函数
#9-4  tepply（数据，性别，mean）
#9-5  星号分别代表输入和输出的形式

#9.10
#9-1
wayans <- list(
  "Dwayne Kim" = list(),
  "Keenen Ivory" = list(
    "Jolie Ivory Imani",
    "Nala",
    "Keenen Ivory Jr",
    "Bella",
    "Daphne Ivory"
  ), 
  Damon = list(
    "Damon Jr",
    "Michael",
    "Cara Mia",
    "Kyla"
  ),
  Kim = list(),
  Shawn = list(
    "Laila",
    "Illia",
    "Marlon"
  ),
  Marlon = list(
    "Shawn Howell",
    "Arnai Zachary" ),
  Nadia = list(),
  Elvira = list(
    "Damien",
    "Chaunté"
  ),
  Diedre = list(
    "Craig",
    "Gregg",
    "Summer",
    "Justin",
    "Jamel"
  ), 
  Vonnie = list()
)

length(wayans)
sum(sapply(wayans,length))


#测试数据
a_liat <- list(
  list(c(3,5,4),"ha"),
  c(1,2,3,4)
)
str(a_liat)

state.x77
summary(state.x77)
str(state.x77)
apply(state.x77,2,mean)
apply(state.x77,2,sd)


commute_times <- replicate(1000, time_for_commute())
commute_data <- data.frame(
  time = commute_times,
  mode = names(commute_times) 
)
commute_data
as.vector(commute_data)
#计算分位数
summary(commute_data)
with(commute_data,split(time,mode))


