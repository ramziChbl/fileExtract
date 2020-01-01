library(FactoMineR)
testData <-read.csv("road.csv", row.names=1)
testData
summary(testData)
res <- PCA(testData[,1:6])
