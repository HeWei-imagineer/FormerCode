#C5.0决策树，决定银行高风险贷款
credit <- read.csv("C://credit.csv")
str(credit)
table(credit$checking_balance)
table(credit$savings_balance)
summary(credit$months_loan_duration)
summary(credit$amount)
summary(credit$default)
set.seed(12345)
credit_rand <- credit[order(runif(1000)),]
summary(credit$amount)
summary(credit_rand$amount)
credit_train <- credit_rand[1:900,]
credit_test <- credit_rand[900:1000,]
prop.table(table(credit_train$default))
prop.table(table(credit_test$default))
install.packages("C50")
library("C50")
credit_model <- C5.0(credit_train[-17],credit_train$default)
credit_model 
summary(credit_model)
credit_pre <- predict(credit_model,credit_test)
library(gmodels)
CrossTable(credit_test$default,credit_pre,prop.chisq = FALSE,
           prop.c = FALSE,prop.r = FALSE,dnn = c('actual default','predicted default'))
credit_boost10 <- C5.0(credit_train[-17],credit_train$default,trials = 10)
credit_boost10
summary(credit_boost10)

credit_boost_pre10 <- predict(credit_boost10,credit_test)
CrossTable(credit_test$default,credit_boost_pre10,prop.chisq = FALSE,
           prop.c = FALSE,prop.r = FALSE,dnn = c('actual default','predicted default'))

error_cost <- matrix(c(0, 1, 4, 0), nrow = 2)
error_cost 
credit_cost<- C5.0(credit_train[-17],credit_train$default,costs = error_cost)
credit_cost_pred <- predict(credit_cost,credit_test)

CrossTable(credit_test$default, credit_cost_pred, prop.chisq = FALSE, prop.c = FALSE, prop.r = FALSE,dnn = c('actual default', 'predicted default'))
