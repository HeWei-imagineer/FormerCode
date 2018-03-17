#11
attach(mtcars)
str(mtcars)
plot(wt,mpg)
detach(mtcars)
colors()[1:10]#查看前10种颜色
#par()函数
par(mfrow = c(length(colors())%/%60+1,1))
par(mar = c(0.1,0.1,0.1,0.1),xaxs = "i",yaxs = "i")
for(i in 1:(length(colors())%/%60+1)){
  barplot(rep(1,60),col = colors()[((i-1)*60+1):(i*60)],
          border = colors()[((i-1)*60+1):(i*60)],axes=FALSE)
          box()
}

#palette()固定调色板函数
palette()
palette(colors()[1:10])
palette()
palette("default")
palette()
data(mtcars)
par(mfrow=c(1,1))
#col描点的颜色
plot(mtcars$wt,mtcars$mpg,col = "blue")
plot(mtcars$wt, mtcars$mpg, col = 4)
plot(mtcars$wt,mtcars$mpg,col='red',xlim = c(1.3,5.6),ylim = c(8,35))
#加点
points(wt[cyl == 6], mpg[cyl == 6], col = "blue")
points(wt[cyl == 8], mpg[cyl == 8], col = "green")
rgb <- rgb(red = 255, green = 1:255, blue = 0, max = 255)
par(mfrow = c(6, 1))
par(mar = c(0.1, 0.1, 2, 0.1), xaxs = "i", yaxs = "i")
barplot(rep(1, 255), col =  rgb, border = rgb, axes = FALSE, main = "rgb"); box()
barplot(rep(1, 100), col = rainbow(100), border = rainbow(100), axes = FALSE, 
        main = "rainbow(100))"); box()
barplot(rep(1, 100), col = heat.colors(100), border = heat.colors(100), 
        axes = FALSE, main = "heat.colors(100))"); box()
barplot(rep(1, 100), col = terrain.colors(100), border = terrain.colors(100), 
        axes = FALSE, main = "terrain.colors(100))"); box()
barplot(rep(1, 100), col = topo.colors(100), border = topo.colors(100), 
        axes = FALSE, main = "topo.colors(100))"); box()
barplot(rep(1, 100), col = cm.colors(100), border = cm.colors(100), axes = FALSE, 
        main = "cm.colors(100))"); box()
# RColorBrewer包
library(RColorBrewer)
par(mar = c(0.1, 3, 0.1, 0.1), mfrow = c(1, 1))
display.brewer.all(type = "seq")
display.brewer.all(type = "div")
display.brewer.all(type = "qual")

library(RColorBrewer)
attach(mtcars) 
cl <- brewer.pal(3, "Dark2")
par(mfrow = c(1, 1))
plot(wt, mpg, col = cl[1])
points(wt[cyl == 6], mpg[cyl == 6], col = cl[2])
points(wt[cyl == 8], mpg[cyl == 8], col = cl[3])
legend(5, 35, c(4, 6, 8), pch = 1, col = cl, bty = "n")

cl <- rainbow(3)
plot(wt, mpg, col = cl[1])
points(wt[cyl == 6], mpg[cyl == 6], col = cl[2])
points(wt[cyl == 8], mpg[cyl == 8], col = cl[3])
legend(5, 35, c(4, 6, 8), pch = 1, col = cl, bty = "n")


plot(1, col = "white", xlim = c(1, 8), ylim = c(1, 7))
symbol <- c("*", "、", ".", "o", "O", "0", " + ", " - ", "|")

for (i in c(0:34)) {
  x <- (i %/% 5) * 1 + 1
  y <- 6 - (i %% 5)
  if (i > 25) {
    points(x, y, pch = symbol[i - 25], cex = 1.3)
    text(x + 0.5, y + 0.1, labels = paste("pch = ", symbol[i - 25]), cex = 0.8)
  } else {
    if (sum(c(21:25) == i) > 0) { 
      points(x, y, pch = i, bg = "red", cex = 1.3)
    } else {
      points(x, y, pch = i, cex = 1.3)
    }
    text(x + 0.5, y + 0.1, labels = paste("pch = ", i), cex = 0.8)
  }
}


attach(mtcars)
cyl <- as.factor(cyl)
plot(wt, mpg, col = "white")
points(wt, mpg, pch = as.integer(cyl) + 1, col = as.integer(cyl) + 1)
legend(5, 35, c(4, 6, 8), pch = 2:4, col = 2:4, bty = "n")

plot(wt, mpg, pch = as.integer(cyl) + 1, col = as.integer(cyl) + 1)
legend(5, 35, c(4, 6, 8), pch = 2:4, col = 2:4, bty = "n")

detach(mtcars)

plot(c(0:5), col = "white", xlab = "", ylab = "")
title(main = list("主标题", cex = 1.5), sub = list("副标题", cex = 1.2),
      xlab = "x轴标题", ylab = "y轴标题")


plot(c(0:5), col = "white")
text(2, 4, labels = "font = 1:正常字体（默认）", font = 1)
text(3, 3, labels = "font = 2:粗体字体", font = 2)
text(4, 2, labels = "font = 3:斜体字体", font = 3)
text(5, 1, labels = "font = 4:粗斜体字体", font = 4)
# 大小
plot(c(0:6), col = "white", xlim = c(1, 8))
text(2, 5, labels = "cex = 0.5:放大0.5倍", cex = 0.5)
text(3, 4, labels = "cex = 0.8:放大0.8倍", cex = 0.8)
text(4, 3, labels = "cex = 1(默认):正常大小", cex = 1)
text(5, 2, labels = "cex = 1.2:放大1.2倍", cex = 1.2)
text(6, 1, labels = "cex = 1.5:放大1.5倍", cex = 1.5)


plot(c(0:5), col = "white")
mtext("side = 1:下边", side = 1, line = 2); mtext("side = 2:左边" , side = 2, line = 2)
mtext("side = 3:上边", side = 3); mtext("side = 4:右边" , side = 4) 

cyl <- as.factor(cyl)
plot(wt, mpg, col = "white", xlab = "", ylab = "")
text(wt, mpg, cyl, col = as.integer(cyl) + 1)
title(main = list("Miles per Gallon vs. Weight by Cylinder", cex = 1.5), 
      xlab = "Weight", ylab = "Miles per Gallon")

plot(wt, mpg, pch = as.character(cyl), col = as.integer(cyl) + 1, 
     xlab = "Weight", ylab = "Miles per Gallon ", 
     main = "Miles per Gallon vs. Weight by Cylinder", cex.main = 1.5)


data <- matrix(rep(rep(1:7), 10), ncol = 10, nrow = 7)
data
plot(data[1, ], type = "l", lty = 0, ylim = c(1, 8), xlim = c(-1, 10), axes = F)
text(0, 1, labels = "lty = 0")
for (i in c(2:7)) {
  lines(data[i, ], lty = i - 1)
  text(0, i, labels = paste("lty = ", i - 1))
}
data <- matrix(rep(rep(1:6), 10), ncol = 10, nrow = 6)
plot(data[1, ], type = "l", lwd = 0.5, ylim = c(1, 8), xlim = c(-1, 10), axes = F); text(0, 1, labels = "lwd = 0.5")
lines(data[2, ], type = "l", lwd = 0.8);text(0, 2, labels = "lwd = 0.8")
lines(data[3, ], type = "l", lwd = 1);text(0, 3, labels = "lwd = 1")
lines(data[4, ], type = "l", lwd = 1.5);text(0, 4, labels = "lwd = 1.5")
lines(data[5, ], type = "l", lwd = 2);text(0, 5, labels = "lwd = 2")
lines(data[6, ], type = "l", lwd = 4);text(0, 6, labels = "lwd = 4")


plot(c(0:10), col = "white")
abline(h = c(2, 6, 8))
abline(v = seq(2, 10, 2), lty = 2, col = "blue")
abline(a = 2, b = 1)


plot(c(0:10), col = "white")
segments(2, 1, 4, 8)
arrows(4, 0, 7, 3, angle = 30)
arrows(4, 2, 7, 5, angle = 60) 

plot(c(0:10), col = "white") 
grid(nx = 4, ny = 8, lwd = 1, lty = 2, col = "blue") 

set.seed(123) 
x <- rnorm(500) 
plot(density(x))
rug(x , col = "blue") 

smpg <- (mpg - min(mpg)) / (max(mpg) - min(mpg))
plot(wt, smpg, ylab = "standardized mpg")
lines(density(wt), col = "red")
arrows(1.8, 0.05, 1.5, 0.1, angle = 10, cex = 0.5)
text(2, 0.05, "核密度曲线", cex = 0.6)
abline(lm(smpg ~ wt), lty = 2, col = "green")
arrows(2, 0.5, 2, 0.7, angle = 10, cex = 0.5)
text(2, 0.45, "回归线", cex = 0.6)
segments(min(wt), max(smpg), max(wt), min(smpg), lty = 3, col = "blue")
arrows(3, 0.8, 2.5, 0.76, angle = 10, cex = 0.5)
text(3.3, 0.8, "最大最小值线段", cex = 0.6)
grid(nx = 4, ny = 5, lty = 2, col = "grey")

par(mfrow = c(1, 3))
plot(density(wt), col = "red")
plot(wt, fitted(lm(smpg ~ wt)), type = "l", lty = 2, col = "green")  # 绘制回归线
plot(seq(min(wt), max(wt), length = 100), seq(max(smpg), min(smpg), length = 100), 
     type = "l", lty = 3, col = "blue")  # 绘制最大、最小值线

local <- c("bottomright", "bottom", "bottomleft", "left", "topleft", "top", 
           "topright", "right", "center")
par(mar = c(4, 2, 4, 2), pty = 'm')
plot(c(0:10), col = "white")
legend(3, 8, "图例在(3, 8)", cex = 0.6)
legend(1, 13, "图例在(11, 11)", xpd = T, cex = 0.6)
for (i in 1:9) {
  legend(local[i], paste("图例在", local[i]), cex = 0.6)
}


plot(c(1:12), col = "white", xaxt = "n", yaxt = "n", ann = FALSE)
axis(1, at = 1:12, col.axis = "red", 
     labels = c("Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",  "Aug", 
                "Sep", "Oct", "Nov", "Dec"))
axis(2, at = seq(1, 12, length = 10), col.axis = "red", labels = 1:10, las = 2)
axis(3, at = seq(1, 12, length = 7), col.axis = "blue", cex.axis = 0.7, 
     tck = -.01, labels = c("Mon", "Tues", "Wed", "Thu", "Fri", "Sat", "Sun")) 
axis(4, at = seq(1, 12, length = 10), col.axis = "blue", cex.axis = 0.7, 
     tck = -.01, labels = round(seq(0, 1, length = 10), 1), las = 2)

mfrow1 <- par(mfrow = c(2, 3))
for (i in 1:6) {
  plot(c(1:i), main = paste("I'm image:", i))
}

mar1 <- par(mar = c(4, 5, 2, 3))
for (i in 1:6) {
  plot(c(1:i), main = paste("I'm image:", i))
}
par(mar1) 
oma1 <- par(oma = c(4, 5, 2, 3))
for (i in 1:6) {
  plot(c(1:i), main = paste("I'm image:", i))
}
par(oma1)  
mgp1 <- par(mgp = c(1, 2, 3))
for (i in 1:6) {
  plot(c(1:i), main = paste("I'm image:", i))
}
par(mgp1) 
par(mfrow1) 

mat <- matrix(c(1, 1, 2, 3, 3, 4, 4, 5, 5, 6), nrow = 2, byrow = TRUE)
layout(mat)
for (i in 1:6) {
  plot(c(1:i), main = paste("I'm image:", i))
}

windows() 
attach(mtcars)
plot(wt, mpg)
X11()  # 打开图形设备界面
plot(wt, mpg)

pdf("p.pdf")
plot(wt, mpg)    
dev.off()

op <- par(mfrow = c(2, 3), mar = c(4, 4, 2, 0.5), mgp = c(2, 0.5, 0))
hist(wt, main = "freq = TRUE")  
hist(wt, breaks = 5, main = "breaks = 5")  
hist(wt, col = "light blue", main = "colored") 
hist(wt, freq = FALSE, main = "freq = FALSE") 
hist(wt, breaks = 40, main = "breaks = 40")  
hist(wt, freq = FALSE, main = "with density curve and normal curve")   
lines(density(wt), col = "blue")
lines(density(rnorm(1e+6, mean(wt), sd(wt))), lty = 2, col = "red") 
par(op) 

install.packages("sm")
library(sm) 
par(mfrow = c(1, 1))
sm.density.compare(wt, factor(cyl))
legend("topright", levels(factor(cyl)), lty = 1:3, col = 2:4, bty = "n")


set.seed(1234) 
normal <- rnorm(100, mean(wt), sd(wt)) 
op <- par(mfrow = c(1, 3))
boxplot(list(wt, normal), xaxt = "n") 
axis(1, at = 1:2, labels = c("wt", "normal"))  
rug(wt, side = 2, col = 2); rug(normal, side = 4, col = 3)  
legend("bottomleft", c("wt", "normal"), lty = 1, col = 2:3, bty = "n") 
boxplot(list(wt, normal), xaxt = "n", varwidth = TRUE)
rug(wt, side = 2, col = 2); rug(normal, side = 4, col = 3) 
axis(1, at = 1:2, labels = c("wt", "normal"))
legend("bottomleft", c("wt", "normal"), lty = 1, col = 2:3, bty = "n")
boxplot(wt ~ cyl)
rug(wt[cyl == 4], side = 2, col = 2); rug(wt[cyl == 6], side = 4, col = 3)
rug(wt[cyl == 8], side = 2, col = 4)
legend("topleft", c("4", "6", "8"), lty = 1, col = 2:4, bty = "n")
par(op)

par(fig = c(0, 1, 0.5, 1), mfrow = c(2, 1))
install.packages("vioplot")
library(vioplot)
vioplot(wt[cyl == 4], wt[cyl == 6], wt[cyl == 8], border = "black", 
        col = "light green", rectCol = "blue", horizontal = TRUE)
par(fig = c(0, 1, 0, .5), mar = c(0, 2, 0, 0.5) , new = TRUE)
boxplot(wt ~ cyl, horizontal = TRUE, pars = list(boxwex = 0.1), border = "blue")
par(fig = c(0, 0.53, 0.1, 0.2), new = TRUE)
plot(density(wt[cyl == 4], bw = 0.3), xaxt = "n", yaxt = "n", ann = FALSE, bty = "n")
par(fig = c(0.26, 0.56, 0.25, 0.35), new = TRUE)
plot(density(wt[cyl == 6], bw = 0.3), xaxt = "n", yaxt = "n", ann = FALSE, bty = "n")
par(fig = c(0.33, 1, 0.4, 0.5), new = TRUE)
plot(density(wt[cyl == 8], bw = 0.5), xaxt = "n", yaxt = "n", ann = FALSE, bty = "n")

# 示例：以mtcars为例，绘制的条形图，见图：
bardata <- table(cyl, carb)  # 得到表格数据
bardata
pal <- RColorBrewer::brewer.pal(3, "Set1")  # 颜色调配
op <- par(mfrow = c(2, 2), mar = c(3, 3, 3, 2), mgp = c(1.5, 0.5, 0))  
barplot(bardata, col = pal, beside = TRUE, xlab = "carb")  # 分组条形图
legend("topright", c("4", "6", "8"), pch = 15, col = pal, bty = "n")
barplot(bardata, col = pal, xlab = "carb")  # 默认堆砌条形图
legend("topright", c("4", "6", "8"), pch = 15, col = pal, bty = "n")
barplot(bardata, col = pal, beside = TRUE, horiz = TRUE, ylab = "carb")  # 水平放置的条形图
legend(5.3, 26, c("4", "6", "8"), pch = 15, col = pal, bty = "n", cex  =  0.6)
barplot(bardata, col = pal, beside = TRUE, ylim = c(0, 7), xlab = "carb")     
legend("topright", c("4", "6", "8"), pch = 15, col = pal, bty = "n")
# 显示数值
text(labels = as.vector(bardata), cex = 0.7, x = c(1.5:23.5)[1:23 %% 4 > 0], 
     y = as.vector(bardata) + 0.5)
par(op)

dotchart(bardata, bg = pal) 

percent <- as.vector(table(cyl)) / sum(as.vector(table(cyl))) * 100  # 计算百分比
pie(table(cyl), labels = paste(c("4", "6", "8"), "cylinders:", percent, "%"))  # 画饼图



methods("plot")



plot(density(wt), type = "l")
class(density(wt))  
plot(table(cyl, vs))
class(table(cyl, vs)) 
opr <- par(mfrow = c(2, 3), mar = c(4, 4, 2, 4))    
for (i in 1:6) {
  plot(lm(mpg ~ wt), i)
}
par(opr); class(lm(mpg ~ wt))
plot(mtcars[, c(1, 3:7)])
class(mtcars[, c(1, 3:7)]) 
x <- seq(from = 0, to = 2*pi, length = 10) 
y <- sin(x)  
type <- c("p", "l", "b", "o", "c", "h", "s", "S", "n" )  
op <- par(mfrow = c(3, 3), mar = c(4, 4, 1, 1))
for (i in 1:9) {
  plot(x, y, type = type[i] , main = paste("type:", type[i]))
}
par(op)  


pairs( ~ mpg + disp + drat + wt, data = mtcars, col = as.integer(factor(cyl)) + 1, 
       main = "Scatter Plot Matrix")
pairs(mtcars[, c(1, 3, 5, 6)], col = as.integer(factor(cyl)) + 1, 
      main = "Scatter Plot Matrix")


install.packages("corrgram")
library(corrgram)
corrgram(mtcars, order = TRUE, upper.panel = panel.ellipse, 
         main = "Correlogram of mtcars intercorrelations")
corrgram(mtcars, order = TRUE, upper.panel = panel.pts, lower.panel = panel.pie, 
         main = "Correlogram of mtcars intercorrelations")

op <- par(mfrow = c(1, 2))
attach(mtcars)
qqnorm(wt)  
qqline(wt) 
qqplot(qt(ppoints(length(wt)), df  =  5), wt, xlab  =  "Theoretical Quantiles", 
       ylab  =  "Sample Quantiles", main  =  "Q-Q plot for t dsn")  # t分布QQ图
qqline(wt) 
par(op)

mosaicdata <- ftable(cyl, vs)  # 二维列联表
par(mfrow = c(1, 1))
mosaicplot(mosaicdata, shade = TRUE, main = "")  # 绘制马赛克图

pal <- RColorBrewer::brewer.pal(11, "Set1")
op <- par(mai = c(0.3, 0, 0, 0))
stars(mtcars, len = 1, key.loc = c(16, 1.5), col.segments = pal, 
      ncol = 9, main = "", draw.segments = TRUE)
par(op)

sunflowerplot(mpg, cyl, col = "green", seg.col = "light green")

mtcars1 <- data.frame(wt, mpg)  
library(KernSmooth)
est <- bkde2D(mtcars1, apply(mtcars1, 2, dpik))  # 计算二维核密度
contour(est$x1, est$x2, est$fhat, nlevels  = 15, col = "darkgreen", 
        xlab = "wt", ylab = "mpg")  # 画等高图
points(mtcars1)

heatmap(as.matrix(mtcars), col = pal, scale = "column")



