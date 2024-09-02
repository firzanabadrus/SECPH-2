View(student_scores)
x <- c(student_scores$absence_days)
y <- c(student_scores$physics_score)

#calculate correlation coefficient
cor(x,y)
cor.test(x,y)

#scatter plot graph
plot(x,y, xlim = c(0,11), ylim = c(50,100), xlab = "Absence Days", ylab = "Physics Score", 
     main = "Physics Scores vs Absence Days", col = "red")

model <- lm(y~x)
model
abline(model)
summary(model)

#by steps
#calculate sample correlation test
r <- cor(x,y)
cat("Sample Correlation Test =", r)

#calculate test statistic
n <- length(x)
t_stat <- (r/(sqrt((1-(r*r)/(n-2)))))
cat("Test Statistic", t_stat)

#calculate degree of freedom
df <- n-2
cat("Degree of Freedom =", df)

#summary of the correlation test
cor.test(x,y)
