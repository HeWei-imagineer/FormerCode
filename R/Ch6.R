#第6章函数与环境
an_environment <- new.env()
an_environment[["pythag"]] <- c(12,23,11,1)
an_environment$root <- polyroot(c(6,-5,1))
assign("monday",weekdays(as.Date("1999/02/09")))
assign("monday",weekdays(as.Date("1999/02/09")),an_environment)
an_environment[["pythag"]]
an_environment$root
get("moonday",an_environment)
get("monday",an_environment)
ls(envir = an_environment)
ls.str(envir = an_environment)
#环境和列表可以相互转换
(a_list <- as.list(an_environment))
as.environment(a_list)
list2env(a_list)
nested_environment <- new.env(parent = an_environment)
exists("pythag",nested_environment)
nested_environment
exists("pythag",nested_environment,inherits = FALSE)
get("pythag")
get("pythag",envir = globalenv())
get("pythag",envir = an_environment)
head(ls(envir = baseenv()),20)
#function
hypotenuse <_- function(x,y){sqrt(x^2+y^2)}
hypotenuse <- function(x,y){sqrt(x^2+y^2)}
hypotenuse(3,4)
formals(hypotenuse)
args(hypotenuse)
formalArgs(hypotenuse)
body(hypotenuse)
deparse(hypotenuse)
dfr1 <- data.frame(x=1:5,y=rt(5,1))
dfr1 <- data.frame(x=6:10,y=rt(5,1,1))
dfr1 <- data.frame(x=11:15,y=rbeta(5,1,1))
do.call
do.call(rbind,list(dfr1,dfr2,dfr3))
dfr1 <- data.frame(x=1:5,y=rt(5,1))
dfr2 <- data.frame(x=6:10,y=rt(5,1,1))
dfr <- data.frame(x=11:15,y=rbeta(5,1,1))
do.call(rbind,list(dfr1,dfr2,dfr3))
dfr3 <- data.frame(x=11:15,y=rbeta(5,1,1))
do.call(rbind,list(dfr1,dfr2,dfr3))
do.call#调用其他函数



#Ch6
#6.5
#6-1   父环境？
#6-2   as.environment()    list2evn()
#6-3   function
#6-4   formals()  args()  formalArgs()
#6-5   do.call()  调用函数，以向量的形式传递参数



#6.6
#6-1
multiple_of_pi <- new.env()
multiple_of_pi[["two_pi"]] <- 2*pi
multiple_of_pi$three_pi <- 3*pi
assign("four_pi",4*pi,envir = multiple_of_pi)
ls(envir = multiple_of_pi)

#6-2
myfunction <- function(x){if(is.finite(x)==FALSE){
                            return(NA)}else if(x%%2==0){
                                   return(TRUE)}else{
                               return(FALSE)}
                          }
myfunction(3)
myfunction(2)
myfunction(Inf)

#6-3
myfunction2 <- function(x){if(is.function(x)==TRUE){
  return(list(args=args(x),body=body(x)))
}
}
(myfunction2(myfunction))


