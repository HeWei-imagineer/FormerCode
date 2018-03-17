#/Users/apple/Desktop/大三上/R语言与机器学习/实验/6/bankloan.csv
#1.绘制违约与不违约客户的年龄、教育和工龄的条形图、点图
data <- read.csv("/Users/apple/Desktop/大三上/R语言与机器学习/实验/6/bankloan.csv")
str(data)
attach(data)
bardata <- table(default, age)  # 得到表格数据
dotchart(bardata,bg = c("blue","red"),ylab = "age")
barplot(bardata,col=c("blue","red"), beside = TRUE, ylab = "age")  # 分组条形图
bardata <- table(default, education)  # 得到表格数据
dotchart(bardata,bg = c("blue","red"),ylab = "education")
barplot(bardata,col=c("blue","red"),beside = TRUE, ylab = "education")  # 分组条形图
bardata <- table(default, seniority)  # 得到表格数据
dotchart(bardata,bg = c("blue","red"),ylab = "seniority")
barplot(bardata,col=c("blue","red"),beside = TRUE, ylab = "seniority")  # 分组条形图
legend("bottomright", c("0", "1"), pch = 15, col = c("blue","red"), bty = "n")

#2.绘制直方图、核密度图、箱线图、小提琴图
hist(age)
hist(education)
hist(seniority)
hist(income)
hist(debt_rate)

library(sm)

sm.density.compare(income,factor(education))
title(main = "income group by education")
legend("topright", levels(factor(education)),lty = 1:3,col =2:6, bty = "n")

sm.density.compare(debt_rate,factor(education))
title(main = "debt_rate group by education")
legend("topright", levels(factor(education)),lty = 1:3,col =2:6, bty = "n")

sm.density.compare(debt_rate,factor(seniority))
title(main = "debt_rate group by seniority")
legend("topright", levels(factor(seniority)),lty = 1:3,col =2:6, bty = "n")

boxplot(list(age,income),xaxt = "n")
axis(1,at=1:2,labels = c("age","income"))
rug(age, side = 2, col = 2); rug(income, side = 4, col = 3)
legend("topleft", c("age", "income"), lty = 1, col = 2:3, bty = "n") 


boxplot(list(education,income),xaxt = "n")
axis(1,at=1:2,labels = c("education","income"))
rug(age, side = 2, col = 2); rug(income, side = 4, col = 3)
legend("topleft", c("education", "income"), lty = 1, col = 2:3, bty = "n") 
install.packages("vioplot")
library(vioplot)

pairs(~age+education+seniority+income+debt_rate,data = data)

