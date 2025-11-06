library(tidyverse)
library(quantreg)
library(brms)
library(MASS)
library(ggplot2)
library(mgcv)
library(dplyr)
library(prettyglm)
library(scales)


Market <- read.csv(file="C:\\Users\\abroek\\OneDrive - Chapman University\\Desktop\\2kool4\\CPSC 540\\Assignment 1\\marketingcampaign.csv", stringsAsFactors=TRUE)


#view(Market)
#plot(Market$past_purchases~Market$age+Market$gender+Market$age*Market$gender)
ans<-glm.nb(past_purchases~age+gender+age*gender, data=Market )

#print(summary(ans))






#gender vs past purchases
vis<- ggplot(data=Market, 
mapping = aes(x=gender, y=past_purchases)) + geom_bar(stat='identity')
#print(vis)



#Trying for the big bananna 
vis1<- ggplot(data=Market, 
mapping = aes(x=age, y=past_purchases))  +
  geom_point(alpha=1)+
  geom_smooth(data=ans, method=glm.nb, se=FALSE)+
  facet_wrap(~gender) 
  

print(vis1)

#Create a dataframe with gender and its count
#gen<-c(Market$gender)
#genCount<-table(gen)
#genCount<-as.data.frame(genCount)
#print(genCount)


#calc percentage of each gender
#pct<- round(100*genCount$Freq/sum(genCount$Freq))


#graph a pie chart of 
#mypie<-pie(genCount$Freq, 
#  labels=paste(genCount$gen, sep=" ", pct,"%"),
#col=rainbow(length(genCount$Freq)))
#print(mypie)
#Data visualization; must be run in R itself to produce html output


#one_way_ave(feature_to_plot = "age",
#model_object = ans, target_variable = "past_purchases", data_set = Market, facetby = "gender",width=1080, height=1080)



