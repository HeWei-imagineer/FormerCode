launch <- read.csv("/Users/apple/Desktop/大三上/R语言与机器学习/实验/6/B6/challenger.csv")
b <- cov(launch$temperature,launch$distress_ct)/var(launch$temperature)
a <- mean(launch$distress_ct)-b*mean(launch$temperature)
r = cov(launch$temperature,launch$distress_ct)/(sd(launch$temperature)*sd(launch$distress_ct))
r
cor(launch$temperature,launch$distress_ct)
reg <- function(y,x){
  x <- as.matrix(x)
  x <-cbind(Intercept = 1,x)
  solve(t(x) %*% x) %*% t(x) %*% y
}
str(launch)
reg(y = launch$distress_ct,x = launch$temperature)
reg(y = launch$distress_ct,x = launch[2:4])


