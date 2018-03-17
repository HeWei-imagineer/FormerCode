if(TRUE) message("silly girl")
#else必须与if语句的右大括号紧接在同一行
if(runif(1)>0.5){
  message("this message appears with a 50% chance")
}else{
  message("this message appears with a another 50% chance")
}
reality <- if(Re(x)==0)"real" else "imaginary"

#ifelse()对应第一个参数，第二三个参数每次均往后移一次
yn <- rep.int(c(TRUE,FALSE),6)
ifelse(yn,1:2,-1:-8)
yn[c(3, 6, 9, 12)] <- NA
ifelse(yn, 1:3, -1:-12)

(greet <- switch("alpha",alpha=1,beta=sqrt(4),
                gamma = {
                  a <- sin(pi/3)
                  4*a^2
                }
))
(greet <- switch("beta",alpha=1,beta=sqrt(4),
                 gamma = {
                   a <- sin(pi/3)
                   4*a^2
                 }
))

(greet <- switch("alph",alpha=1,beta=sqrt(4),
                 gamma = {
                   a <- sin(pi/3)
                   4*a^2
                 }
                 ,4
))

switch(
     8,
     "first",
    "second",
     "third",
     8,
    6,
    7
   )

switch(
     as.character(2147483647),
     "2147483647" = "a big number",
     "another number" 
   )

repeat {
  message("Happy Groundhog Day!") 
}
repeat{
  message("happy birth day!")
  action <- sample(
    c(
      "a",
      "d",
      "e"
    ),
    1
  )
  message("action = ",action)
  if(action=="e")break;
}
repeat{
  message("happy birth day!")
  action <- sample(
    c(
      "a",
      "d",
      "e"
    ),
    1
  )
  if(action=="a"){
    message("to next")
    next
  }
  message("action = ",action)
  if(action=="e")break;
}

#
action <- sample(
     c(
         "Learn French",
         "Make an ice statue",
         "Rob a bank",
        "Win heart of Andie McDowell"
       ),
     1
   )

while(action !="Win heart of Andie McDowell")
{
  message("happy groundhog day!")
  action <- sample(
    c(
      "Learn French",
      "Make an ice statue",
      "Rob a bank",
      "Win heart of Andie McDowell"
    ),
    1
  )
  message("action = ", action) 
}


#for 可接收字符向量，逻辑向量，列表
for(month in month.name)
{
  message("the month of ",month)
}

l <- list(
     pi,
     LETTERS[1:5],
     charToRaw("not as complicated as it looks"),
     list(
         TRUE
      )
   )
 for(i in l) 
   { 
       print(i)
     }

#8.5
#8-1   会报错
#8-2   会输出NA值
#8-3   数字，字符
#8-4   先执行一次，再判断条件
#8-5   next关键字

two_d6 <- function(n) 
{
  random_numbers <- matrix(
    sample(6, 2 * n, replace = TRUE),
    nrow = 2 
  ) 
  colSums(random_numbers) 
}
two_d6(2)

if(two_d6(2)==2|12|3){
  message("aa")
}

#record函数先判断射手第一次掷骰子的结果，之后根据结果判断是否继续，最后输出游戏结果
Point 
recored <- function(x){
       first <- switch(as.character(x),
       "2" = {Game_status=FALSE
       Point=NA
       message(Game_status)},
       "3" = {Game_status=FALSE
       Point=NA
       message(Game_status)},
       "12" = {Game_status=FALSE
       Point=NA
       message(Game_status)},
       "7" = {Game_status=TRUE
       Point=NA
       message(Game_status)},
       "11" = {Game_status=TRUE
       Point=NA
       message(Game_status)},
       {Game_status=NA
       Point=x}
       )
      
       if(!is.na(Point)){
         message("game continue")
         while(Point!=7){
          Point1 = two_d6(1)
          if(Point==Point1){
            message("win")
            break
          }else{
            Point=Point1
          }
         }
         
       }else{
         message(Game_status)
       }
}
recored(two_d6(1))

sea_shells <- c(
  "She", "sells", "sea", "shells", "by", "the", "seashore", "The", "shells", "she", "sells", "are", "surely", "seashells", "So", "if", "she", "sells", "shells", "on", "the", "seashore", "I'm", "sure", "she", "sells", "seashore", "shells"
)

a <- list(1:9)
length(a) <- 9

b <- rep.int(0,9)
b

for(i in sea_shells){
  switch(as.character(nchar(i)),
         "2"={
          a[[nchar(i)]][b[1]] <- i
          b[1] <- b[1]+1
         },

          "3"={
            a[[nchar(i)]][b[2]] <- i
            b[2] <- b[2]+1
          },
          "4"={
            a[[nchar(i)]][b[1]] <- i
            b[3] <- b[3]+1
          },
          "5"={
            a[[nchar(i)]][b[4]] <- i
            b[4] <- b[4]+1
          },
          "6"={
            a[[nchar(i)]][b[5]] <- i
            b[5] <- b[5]+1
          },
          "7"={
            a[[nchar(i)]][b[6]] <- i
            b[6] <- b[6]+1
          },
         "8"={
           a[[nchar(i)]][b[7]]<- i
           b[7] <- b[7]+1
         },
          "9"={
           a[[nchar(i)]][b[8]] <- i
           b[8] <- b[8]+1
         }
         )
  message(i)
  }
a
