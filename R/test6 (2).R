insurance <- read.csv("/Users/apple/Desktop/大三上/R语言与机器学习/实验/6/insurance.csv",stringsAsFactors = TRUE)
str(insurance)
summary(insurance$expenses)
hist(insurance$expenses)
table(insurance$region)
cor(insurance[c("age","bmi","children","expenses")])
#散点图可视化
pairs(insurance[c("age","bmi","children","expenses")])
install.packages("psych")
library(psych)

pairs.panels(insurance[c("age","bmi","children","expenses")])
#训练模型
ins_model <- lm(expenses~.,data = insurance)
ins_model

summary(ins_model)

#提高模型性能

insurance$age2 <-insurance$age^2
str(insurance)
insurance$bmi30 <- ifelse(insurance$bmi>=30,1,0)
charges~bmi30+smokeryes+bmi30:smokeryes

ins_model2 <- lm(expenses~age+age2+children+bmi+sex+bmi30*smoker+region,data = insurance)
summary(ins_model2)
