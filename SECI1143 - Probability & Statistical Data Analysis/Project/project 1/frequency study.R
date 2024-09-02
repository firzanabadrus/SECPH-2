device.Use<-table(ProjectData[,1])
device.Use
barplot(device.Use)
pie(ProjectData)
pie(ProjectData$`Do you frequently use your device?`,ProjectData$X1)
barplot(device.Use)

barplot(device.Use, col="purple", xlab = "usage rate", ylab = "frequency", main = "Respondent Device Usage")

daily.average<-table(ProjectData[,2])
daily.average
boxplot(daily.average)
output = boxplot(daily.average)

boxplot(daily.average, ylab = "hours", main = "Daily Average Screen Time")
device.activity<- table(ProjectData[,3])
device.activity
device.activity.cs<- c(0,cumsum(device.activity))

summary(device.activity)

pie(device.activity)
pie(device.activity, main="Device Usage : Activities & Preferences")
summary(device.activity)
print(device.activity)
percentage(device.activity)
study.freq<-table(ProjectData[,5])
study.freq
pie(study.freq, main = "Frequency of Studying")

device.time<- table(ProjectData[,4])
device.time
plot(breaks, device.time)
lines(breaks, device.time)
breaks <- seq(12 - 4 a.m, 12 - 4 p.m, 4 - 8 p.m, 8 - 12 p.m)
breaks <- seq(2 , 6, 10, 2 , 6, 10)
view(device.time)
midpoint = c(0200, 0600, 1000, 1400, 1800, 2200)
frequency = c(5, 0, 30, 8, 19, 10)
print(device.time
data <- data.frame
  midpoint = c(0200, 0600, 1000, 1400, 1800, 2200)
  frequency = c(5, 0, 30, 8, 19, 10)
print(data)
library(ggplot2)
ggplot(data, aes(x= midpoint, y = frequency)) 
geom_point(size = 3, color = "blue") +  # Add points
  labs(x = "Midpoint", 
       y = "Frequency", 
       title = "Scatter Plot of Midpoint vs. Frequency")
# Create a data frame with your data
data <- data.frame(
  Time_Interval = c("0000 - 0400", "0400 - 0800", "0800 - 1200", 
                    "1200 - 1600", "1600 - 2000", "2000 - 0000"),
  Midpoint = c(200, 600, 1000, 1400, 1800, 2200),
  Frequency = c(5, 0, 30, 8, 19, 10),
  Percentage = c(6.94, 0.00, 41.67, 11.11, 26.39, 13.89)
)

# Print the data frame
print(data)

# Load required libraries
library(ggplot2)

# Create scatter plot using ggplot2
ggplot(data, aes(x = Midpoint, y = Frequency)) +
  geom_point(size = 3, color = "blue") +  # Add points to the plot
  labs(x = "Midpoint", y = "Frequency", title = "Scatter Plot of Time Interval vs. Frequency") +
  geom_text(aes(label = Time_Interval), hjust = -0.2, vjust = 0.5) +  # Add labels for Time_Interval
  theme_minimal()  # Apply a minimal theme

breaks <- seq(0200, 0600, 1000, 1400, 1800, 2200)
data.cs <- c(0,cumsum(data))
summary(data)

daily.average<-table(ProjectData[,2])
daily.average
boxplot(daily.average)
output = boxplot(daily.average)
boxplot(main = "Daily Aerage of Screen Time")
boxplot(daily.average, ylab = "hours", main = "Daily Average of Screen Time")
summary(daily.average)
quantile(daily.average, type=2)

data<- data.frame()
  time_interval = c("0000-0400", "0400-0800", "0800-1200", "1200-1600", "1600-2000", "2000-0000")
  midpoint = c(0200, 0600, 1000, 1400, 1800, 2200)  
  frequency = c(5,0,30,8,19,10)  
  percentage = c(6.94,0.00,41.67,11.11,26.39,13.89)  
print(data)
  plot(data)  
  print(data)
table(data)
hist(data)
print(data)
hist(var, col=color, border=NA,xlim=range,main=title,xlab=x-axis, ylab= y axis)
hist(data$x1)
plot(data)

data1<-data$X1
breaks <- seq(0200, 0600, 1000)
data1.cut <-cut(data1, breaks)
plot(data,data.cs)
barplot(data)
