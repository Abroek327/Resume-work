library(GGally)
library(ggplot2)
library(mgcv)
library(dplyr)
library(nnet)
library(prediction)
library(ggforce)


Market <- read.csv(file="C:\\Users\\abroek\\OneDrive - Chapman University\\Desktop\\2kool4\\CPSC 540\\Assignment 1\\marketingcampaign.csv", stringsAsFactors=TRUE)
#Market$email_signup<-factor(Market$email_signup)
#Market$campaign_variant<-factor(Market$campaign_variant)
#print(glimpse(Market))

model<-glm(campaign_spend~past_purchases+
  ad_source+campaign_variant+email_signup+
  past_purchases*ad_source+past_purchases*campaign_variant+past_purchases*email_signup+
  ad_source*campaign_variant+ad_source*email_signup+
  campaign_variant*email_signup, data=Market)
#print(summary(model))


model1<-glm(campaign_spend~campaign_variant, data=Market)
print(summary(model1))







#past purchases by camp variant
vis<- ggplot(data=Market, 
mapping = aes(x=campaign_variant, y=past_purchases)) + geom_bar(stat='identity')

#print(vis)

#past purchases by email signup
vis1<- ggplot(data=Market, 
mapping = aes(x=email_signup, y=past_purchases)) + geom_bar(stat='identity')

#print(vis1)

#... by ad_source
vis2<- ggplot(data=Market, 
mapping = aes(x=ad_source, y=past_purchases)) + geom_bar(stat='identity')

#print(vis2)

#spend vs variant
vis3 <- ggplot(data=Market, aes(x=campaign_variant, y=campaign_spend)) +
  geom_bar(stat="identity")

#print(vis3)

vis4<-ggplot(data=Market, aes(x=email_signup, y=campaign_spend)) +
  geom_bar(stat="identity")

#print(vis4)

vis5<-ggplot(data=Market, aes(x=ad_source, y=campaign_spend)) +
  geom_bar(stat="identity")

#print(vis5)

#plot # of purchases vs spend broken down by ad group, ad campaign, and email signup; pagination for ad group
vis6<-ggplot(data=Market, aes(x=past_purchases, y=campaign_spend))+
  geom_point(alpha=1, aes(colour=(campaign_variant)))+
  #geom_smooth(data=model, method=glm, se=FALSE)+
  facet_wrap_paginate(~ad_source+ email_signup+campaign_variant, ncol=3, nrow=2 ,page=1)


vis7<-ggplot(data=Market, aes(x=past_purchases, y=campaign_spend))+
  geom_point(alpha=1, aes(colour=(campaign_variant)))+
  #geom_smooth(data=model, method=glm, se=FALSE)+
  facet_wrap_paginate(~ad_source+ email_signup+campaign_variant, ncol=3, nrow=2 ,page=2)

vis8<-ggplot(data=Market, aes(x=past_purchases, y=campaign_spend))+
  geom_point(alpha=1, aes(colour=(campaign_variant)))+
  #geom_smooth(data=model, method=glm, se=FALSE)+
  facet_wrap_paginate(~ad_source+ email_signup+campaign_variant, ncol=3, nrow=2 ,page=3)

vis9<-ggplot(data=Market, aes(x=past_purchases, y=campaign_spend))+
  geom_point(alpha=1, aes(colour=(campaign_variant)))+
  geom_smooth(data=model, method=glm, se=FALSE)+
  facet_wrap_paginate(~ad_source+ email_signup+campaign_variant, ncol=3, nrow=2 ,page=4)
#print(vis6)
#print(vis7)
#print(vis8)
#print(vis9)

#Money each camp made
vis10<-ggplot(data=Market, aes(x=campaign_variant, y=campaign_spend))+
  geom_bar(stat="identity", aes(colour=(campaign_variant)))
  #geom_smooth(data=model, method=glm, se=FALSE)+

#print(vis10)

#number of purchases each camp drove
vis11<-ggplot(data=Market, aes(x=campaign_variant, y=past_purchases))+
   geom_bar(stat="identity", aes(colour=(campaign_variant)))
  #geom_smooth(data=model, method=glm, se=FALSE)+

print(vis11)
#how email signup effected spending
vis11<-ggplot(data=Market, aes(fill= campaign_variant, x=email_signup, y=campaign_spend))+
  geom_bar(position="dodge", stat="identity")
  


#print(vis11)
#which ads performed 
vis12<-ggplot(data=Market, aes(fill= campaign_variant, x=ad_source, y=campaign_spend))+
  geom_bar(position="dodge", stat="identity")

#print(vis12)
#age demo spending by camp variant
vis13<-ggplot(data=Market, aes(fill= campaign_variant, x=age, y=campaign_spend))+
  geom_bar(position=position_dodge(width=1), width=.6, stat="identity")

#print(vis13)

vis14<-ggplot(data=Market, aes(x=past_purchases, y=campaign_spend))+
  geom_point(alpha=.8, aes(colour=(campaign_variant)))
  #+geom_smooth(data=model, method=glm, se=FALSE)

#print(vis14)

subdataA <- Market[which (Market$campaign_variant=="A"),]

#print(head(subdataA))
ggplot(data=subdataA, aes(fill= campaign_variant, x=age, y=campaign_spend))+
  geom_bar( width=.5, stat="identity")

subdataC <- Market[which (Market$campaign_variant=="C"),]


plotC<-ggplot(data=subdataC, aes(fill= campaign_variant, x=age))+
  geom_density(fill="#619cff")+  
  labs(x="Age", y="Revenue")

#print(plotC)

vio<-ggplot(data=Market, aes(x=ad_source, y=age, fill=ad_source))+
  geom_violin(draw_quantiles =  0.5)

print(vio)