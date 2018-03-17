concrete <- read.csv("E://大三//R语言与机器学习//B7//实验//7//concrete.csv")
str(concrete)
normalize <- function(x){
  return((x-min(x))/(max(x)-min(x)))
}
concrete_norm <- as.data.frame(lapply(concrete,normalize))
summary(concrete_norm$strength)

concrete_train <- concrete_norm[1:173,]
concrete_test <- concrete_norm[774:1030,]

install.packages("neuralnet")
library(neuralnet)
#创建神经网络拓扑结构
concrete_model <- neuralnet(strength ~ cement + slag + ash + water
                            + superplastic + coarseagg + fineagg + age,data = concrete_train)
plot(concrete_model)

model_results <- compute(concrete_model,concrete_test[1:8])
predicted_strength <- model_results$net.result
#结果代表其线性关系
cor(predicted_strength,concrete_test$strength)
concrete_model2 <- neuralnet(strength ~ cement + slag + ash + water
                            + superplastic + coarseagg + fineagg + age,data = concrete_train,hidden = 5)
plot(concrete_model2)
model_results2 <- compute(concrete_model2,concrete_test[1:8])
predicted_strength2 <- model_results2$net.result
#结果代表其线性关系
cor(predicted_strength2,concrete_test$strength)
