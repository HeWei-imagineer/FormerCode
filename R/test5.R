mushrooms <- read.csv("E:\\大三\\R语言与机器学习\\5\\mushrooms.csv",stringsAsFactors = TRUE)
str(mushrooms)
mushrooms$veil_type <-NULL
table(mushrooms$type)
install.packages("RWeka")
library(RWeka)
head(mushrooms)
mushroom_1R <- OneR(type~.,data = mushrooms)
mushroom_1R
summary(mushroom_1R)
#为何跟之前的结果一样
mushroom_1R <- OneR(type~ odor + cap_color,data = mushrooms)
mushroom_1R
summary(mushroom_1R)

mushroom_JRiP <- JRip(type~.,data = mushrooms)
mushroom_JRiP
#JRiP算法中每一条规则都选出了一个有毒的品种，这属于数据的特殊性，复杂的数据待考察
