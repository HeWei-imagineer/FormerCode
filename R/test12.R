data <- read.csv("/Users/apple/Desktop/大三上/R语言与机器学习/课件/bankloan.csv")
library(lattice)
library(nutshell)
str(data)
edu <- as.factor(data$education)
histogram(~income|edu,data = data,main="income vs diffrent education",layout=c(1,5),xlab="income")

histogram(~debt_rate|edu,data = data,main="debt_rate vs diffrent education",layout=c(1,5),xlab="debt_rate")

densityplot( ~ income | edu, data = data, layout = c(1, 5), plot.points = FALSE, 
             main = "income vs diffrent education", xlab = "income")
densityplot( ~ income, groups = edu, data = data, plot.points = FALSE, 
             main = "income vs diffrent education", xlab = "income", 
             lty = 1:5, col = 1:5, lwd = 1.5, 
             key = list(text = list(levels(edu)), 
                        column = 3, lines = list(lty = 1:5, col = 1:5)))
densityplot( ~ debt_rate | edu, data = data, layout = c(1, 5), plot.points = FALSE, 
             main = "debt_rate vs diffrent education", xlab = "debt_rate")
densityplot( ~ debt_rate, groups = edu, data = data, plot.points = FALSE, 
             main = "debt_rate vs diffrent education", xlab = "debt_rate", 
             lty = 1:5, col = 1:5, lwd = 1.5, 
             key = list(text = list(levels(edu)), 
                        column = 3, lines = list(lty = 1:5, col = 1:5)))

str(data)
panel <- function(x,y){
  panel.lmline(x, y, col = "red", lwd = 1, lty = 2)
  panel.xyplot(x, y)
}
xyplot(income~age, data = data,panel = panel)
xyplot(debt_rate~age, data = data,panel = panel)
xyplot(income~education, data = data,panel = panel)
xyplot(debt_rate~education, data = data,panel = panel)
xyplot(income~seniority, data = data,panel = panel)
xyplot(debt_rate~seniority, data = data,panel = panel)

data1 <- data[-3:-7]
str(data3)
barchart(data1, auto.key = TRUE,main="default by eduction")
barchart(data1, layout = c(4, 1), 
         auto.key = list(title = "Default", columns = 2), 
         scales = list(x = "free")) 
data2 <-data1[-2]
barchart(data2, auto.key = TRUE,main="default by age")

data3 <-data[-4:-7]
data3 <- data3[,3:4]
str(data3)
barchart(data3, auto.key = TRUE,main="default by seniorty")

xyplot(default~age, data = data,panel = panel)
xyplot(default~education, data = data,panel = panel)
xyplot(default~seniority, data = data,panel = panel)

