#加载包
pkgs <- c("lattice","utils","rpart")
for(pkg in pkgs)
{
  library(pkg,character.only = TRUE)
}
if(!require(apackagethatmightnotbeinstalled)) 
{   
  warning("The package 'apackagethatmightnotbeinstalled' is not available.")   # 或者尝试去下载它   #...
}
#查看所有已加载的包
search()
View(installed.packages())
#查看R安装时自带包的存储位置
R.home("library")
.Library
#查看用户库的位置
path.expand("~")
Sys.getenv("HOME")
update.packages(ask = FALSE)
remove.packages("utils")
(require("utils"))
