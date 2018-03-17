x <- (1:1000)
y <- atan(1/(1:1000))
z <- 1/tan(y)
x == z
identical(x,z)
all.equal(x,z)
all.equal(x,z,0)
5/2
5%/%2
ture_and_mising <- TRUE
false_and_mising <- (FALSE,NA)
false_and_mising <- c(FALSE,NA)
mixed <- c(TRUE,FALSE,NA)
any(ture_and_mising)
any(false_and_mising)
any(mixed)
all(ture_and_mising)
all(false_and_mising)
all(mixed)
charToRaw("abc")
charToRaw("ABC")
num <- c(1,3,4.5,5.5,9,7)
summary(num)
Num <- runif(30)
fac <- factor(sample(letters[1:5],30,replace = TRUE)
3/2
fac <- factor(sample(letters[1:5],30,replace = TRUE))
bool <- factor(sample(c(TRUE,FALSE,NA),30,replace = TRUE))
dfr <- data.frame(Num,fac,bool)
head(dfr)
str(dfr)
unclass(Num)
unclass(fac)
view(dfr)
View(dfr)
new_dfr <- edit(dfr)
ls()
as.numeric("3.45")
a <- as.numeric("3.45")
a
class(a)
class(Inf)
savehistory("~/ch3.Rhistory")
save.image("~/ch3.RData")
ls()
animals <- sample("dog","cat","goldfish","hamster",1000,replace = TRUE)
animals <- sample(c("dog","cat","goldfish","hamster"),1000,replace = TRUE)
summary(animals)
head(animals)
levels(animals)
rm(animals)
animals <- factor(sample("dog","cat","goldfish","hamster",1000,replace = TRUE))
animals <- factor(sample(c("dog","cat","goldfish","hamster"),1000,replace = TRUE))
head(animals)
nlevels(animals)
summary(animals)
cabbage <- 10
potato <- 5
toamto <- 6
rm(toamto)
tomato <- 6
eggplant <- 9
couregette <-1
ls(pattern = "a")
seq_len(0)
seq_len(-2)
seq_along(4)
seq_along(2)
se <- seq_along(3)
summary(se)
s1 <- factor(seq_along(3))
summary(s1)
pp
pp <- (c("ha","ni","zai","na"))
for(i in s1)print(pp[i])
i = 1
for(i in s1)print(pp[i])
length(s1s)
length(s1)
q <- (1,2,3)
q <- (c(1,2,3))
names(q) <- c("wo","hen","sq")
q
names(wo)
names(q)
q["wo"]
q[["wo"]]
rep(1:3,times=1:3)
rep(1:3,times=1:4)
seq.int(0,1,0.25)
save.image("~/ch3.RData")
savehistory("~/ch3.Rhistory")
ls()
angel <- seq_along(20)
for(i in 1:20) angel[i] <- i*(i+1)/2
angel
names(angel) <- sample(letters[1:20],20,replace = TRUE)
angel
angel["a","o","u","e"]
[angel]["a","o","u","e"]
angel["e"]
line1 <- 11:0
line2 <- 1:11
diag(c(line1,line2))
diag(1,nrow = 20,ncol = 21)
Aline <- seq.int(0,0,21)
a_matrix <- diag(1,nrow = 20,ncol = 21)
rbind(Aline,a_matrix)
b_matrix <- a_matrix
rm(b_matrix)
b_matri
b_matrix <- diag(1,nrow = 20,ncol = 21)
rbind(b_matrix,Aline)
rm(b_matrix)
b_matrix<- diag(1,nrow = 21,ncol = 20)
cbind(Aline,b_matrix)
c_matrix <- cbind(Aline,b_matrix)
c_matrix [1,1] <- 1
c_matrix
diag(1,19,19)
c_line <- (0,0,19)
c_line <- seq.int(0,0,19)
rbind(c_line,c)
c_matrix <- diag(1,19,19)
rbind(c_line,c_matrix)
rbind(c_line,c_matrix)
d_line <- seq.int
d_line <- seq.int(0,0,21)
c_matrix <- rbind(c_line,c_matrix)
c_matrix <- rbind(c_line,c_matrix)
c_matrix
c_matrix <- cbind(c_matrix,Aline)
rm(d_line)
c_matrix[1,1] <- 1
c_matrix
c_matrix[1,1] <- 0
c_matrix[21,21] <- 1
nrow(c_matrix)
ncol(c_matrix)
c_matrix <- cbind(c_matrix,Aline)
c_matrix
c_matrix[21,22] <- 1
c_matrix[21,20] <- 1
c_matrix
d_matrix <- c_matrix
c_matrix <- cbind(Aline,b_matrix)
>c_matrix [1,1] <- 1
c_matrix [1,1] <- 1
c_matrix
e_matrix <- c_matrix + d_matrix
f_matrix <- diag(c(line1,line2))
e_matrix <- e_matrix + f_matrix
f_matrix
line1 <- 10:0
line2 <- 1:10
f_matrix <- diag(c(line1,line2))
e_matrix <- e_matrix + f_matrix
eigen(e_matrix)
e_matrix
(a_list <- list(
c(1,1,2,5,14,42),
month.abb,
matrix(c(3,-8,1,-3),nrow = 2),
asin
))
nrow(a_list)
NROW(a_list)
a_list[TRUE,FALSE]
a_list[c(TRUE,FALSE)]
names(a_list) <- c("jin","tian","zenme","yang")
a_list["tian"]
a_list[["tian"]]
a_list$jin
class(a_list)
ls()
v <= 9
v <- 9
ls(pattern = "v")
v <- null
v <- NULL
ls(pattern = "v")
?rnorm()
savehistory("~/ch3.Rhistory")
save.image("~/ch3.RData")
ls()
a_data_frame <- data.frame(
x = letters[1:5],
y = rnorm(5),
z = runif(5)>0.5
)
?subset()
subset(a_data_frame,,"y")
?merge()
?rnorm()x <- 0:99sqrt_x <- sqrt(x)is_square_number <- sqrt_x == floor(sqrt_x)square_numbers <- x[is_square_number] groups <- cut(square_numbers,seq.int(min(x), max(x), 10),include.lowest = TRUE,right = FALSE )split(square_numbers, groups)
v1 <- seq_along(10)
for(i in 1:10)v1[i] <- i*i
v1
iris
ls()
a_frame <- iris
colMeans(a_frame[1:4])
beaver1
b_frame <- beaver1
c_frame <- beaver2
col1 <- rep(1:1,114)
cbind(col1,b_frame)
col2 <- rep(2:2,114)
beaver2
col2 <- rep(2:2,100)
cbind(col2,c_frame)
rbind(b_frame,c_frame)
d_frame <- rbind(b_frame,c_frame)
subset(d_frame,activ==1,activ)
savehistory("~/ch3.Rhistory")
save.image("~/ch3.RData")
#Ch2 代码
1:3 + 5:7
c(1,6,3) + c(5,2,7)
sun(1:10)
sum(1:10)
median(2:6)
median(5:9)
median(1:2)
median(1,2)
median(1,2,3)
c(1,2,3) - 2
-1:3 * 0:4
1:5 / 2
1:5 %% 2
1:5 %/% 2
2^4
2***3
2**3
2**2
sqrt(16)
abs(-16)
log(e)
log(10)
log10(10)
log(9,3)
identical(sqrt(2^2),2)
sin(pi/6)
round(4.2345,3)
round(4.2349,3)
round(4.2346,3)
round(4.2345,3)
floor(4.345)
ceiling
ceiling(5.4)
?factorial()
choose(3,0:3)
choose(3,0:4)
choose(3,5)
?choose()
choose(2,0:1)
ls()
v3 <- factor(c("a","b","c"))
unclass(v3)

#Wilkinson矩阵创建，题目中的表述有歧义，在此重新再次创建该矩阵
a_matrix <- diag(c(10:0,1:10),21,21)
#b_matrix为对角线向下移一行的矩阵
b_matrix <- diag(1,20,20)
b_matrix <- cbind(b_matrix,Bline)
b_matrix <- rbind(Aline,b_matrix)
#C_matrix为对角线向上移一行的矩阵
c_matrix <- diag(1,20,20)
c_matrix <- cbind(Bline,c_matrix)
c_matrix <- rbind(c_matrix,Aline)
d_matrix <- c_matrix + b_matrix
d_matrix <- d_matrix + a_matrix
d_matrix

savehistory("~/201592458何维1.r")
