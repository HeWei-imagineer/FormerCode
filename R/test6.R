insurance <- read.csv("E:\\大三\\R语言与机器学习\\insurance.csv",stringsAsFactors=TRUE)
str(insurance)
summary(insurance$expenses)
hist(insurance$expenses)
table(insurance$region)
cor(insurance[c("age","bmi","children","expenses")])
pairs(insurance[c("age","bmi","children","expenses")])
install.packages("psych")
library(psych)
pairs.panels(insurance[c("age","bmi","children","expenses")])
#拟合线性回归模型
ins_model <- lm(expenses ~ age + children + bmi + sex + smoker + region,data=insurance)
ins_model
#虚拟编码：为每一个特征创建不同类，然后用因子表示
summary(ins_model)

insurance$age2 <- insurance$age^2
insurance$bmi30 <- ifelse(insurance$bmi >= 30, 1, 0)
charges ~ bmi30 + smokeryes + bmi30:smokeryes
charges~age+age2
ins_model2 <- lm(expenses ~ age + age2 + children + bmi + sex +bmi30*smoker + region, data = insurance)
summary(ins_model2)



