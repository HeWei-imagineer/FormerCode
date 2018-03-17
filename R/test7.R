#/Users/apple/Desktop/大三上/R语言与机器学习/实验/7/whitewines.csv
wine <- read.csv("/Users/apple/Desktop/大三上/R语言与机器学习/实验/7/whitewines.csv")
str(wine)
hist(wine$quality)
summary(wine$quality)
wine_train <- wine[1:3750, ]
wine_test <- wine[3751:4898,]
m.rpart <- rpart(quality ~ .,data = wine_train)
m.rpart
summary(m.rpart)

rpart.plot(m.rpart,digits = 4,fallen.leaves = TRUE,type = 3)
p.rpart <- predict(m.rpart,wine_test)
summary(p.rpart)
summary(wine_test$quality)
cor(p.rpart,wine_test$quality)

library(RWeka)
m.m5p <- M5P(quality ~ ., data = wine_train)
m.m5p
p.m5p <- predict(m.m5p, wine_test)
summary(p.m5p)
cor(p.m5p, wine_test$quality)
MAE(wine_test$quality, p.m5p)
