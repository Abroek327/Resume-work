library(tidyverse)
library(quantreg)
library(brms)
library(MASS)
library(ggplot2)
library(mgcv)
library(dplyr)
library(bayestestR)
library(bayesplot)
library(tidybayes)
library(see)
library(hytest)
library(TOSTER)

df <- read_csv(file="C:\\Users\\abroek\\OneDrive - Chapman University\\Desktop\\2kool4\\CPSC 540\\Assignment 2\\hw2.csv", show_col_types = FALSE)
df$group<-as.factor(df$group)

print(head(df))

#Bayseian HT

df$group<-as.numeric(df$group)

priors1<-c(
  prior("cauchy(1,10)", class="b", coef=corgi), 
prior("normal(1.48, 0.5001002 )", class="b", coef=group),
prior("normal(39.136, 12.83632)", class="b", coef=age))

priors2<-c(  
  prior("normal(2.294,1.676062)", class="b", coef=corgi), 
prior("normal(39.136, 12.83632)", class="b", coef=age))

#mod1<-brm(bf(anxiety~group+corgi+ hair_color+age), data=df, prior=priors1, refresh=0, 
#sample_prior = "yes", save_all_pars = TRUE) 
#mod2<-brm(bf(anxiety~corgi+ hair_color+age), data=df, prior=priors2, refresh=0, 
#sample_prior = "yes", save_all_pars = TRUE) 

 
#print(describe_prior(mod1 ))
#print(describe_posterior(mod1))

#Parameter        | Median |         95% CI |     pd |          ROPE | % in ROPE |  Rhat |  ESS
#Group            |   0.70 | [ 0.09,  1.30] | 98.60% | [-0.43, 0.43] |    17.05% | 1.000 | 5853

#Posterior dist. and rope visualization
#view9<-mcmc_dens(mod1, pars = "b_group")
#print(view9)
#vis10<-mcmc_areas(mod1, pars="b_group")
#print(vis10 )

#posterior odds HT
#pp<-post_prob(mod1, mod2, prior_prob = c(0.5,0.5))
#print(pp)

# mod1 (with group)     mod2 (without group) 
#0.09904278             0.90095722 

#mod2 (no group variable included) is much more likely ergo the effect of group is likely null(?)

#Frequentist HT
#df$hair_color<-as.numeric(as.factor(df$hair_color))
#fmod<-glm(anxiety~group+age+corgi+hair_color, data=df)
#print(summary(fmod))
#Coefficients:
#                      Estimate Std. Error t value Pr(>|t|)  
#groupB                0.213516   0.387169   0.551   0.5816 

#df$group<-as.numeric(df$group)





#yummy_toast<-t_TOST(
#  anxiety~group,
#  data=df,
#  eqb=sd(df$anxiety)
#)
#print(yummy_toast)

#Welch Two Sample t-test

#The equivalence test was significant, t(314.31) = 10.37, p < 0.01
#The null hypothesis test was non-significant, t(314.31) = -0.477, p = 0.63
#NHST: don't reject null significance hypothesis that the effect is equal to zero 
#TOST: reject null equivalence hypothesis

#TOST Results 
#                  t    df p.value
#t-test      -0.4773 314.3   0.634
#TOST Lower  10.3749 314.3 < 0.001
#TOST Upper -11.3294 314.3 < 0.001

#Effect Sizes 
#               Estimate      SE              C.I. Conf. Level
#Raw            -0.18988 0.39785 [-0.8462, 0.4665]         0.9
#Hedges's g(av) -0.04322 0.09097 [-0.1922, 0.1058]         0.9
#Note: SMD confidence intervals are an approximation. See vignette("SMD_calcs").

#So, since the equiv test was significant, the effect is practically 0
#However, it is not null(?), and we have no evidence that the effect is different from 0
#Ergo, there is effectively no difference in how the two groups are being led. 


#simple visualizations

#Age vs mental_well; kind of all over the place but mostly young people sadder
vis1<-ggplot(data=df, aes(x=age, y=mental_well))+
  geom_bar(stat="identity")

#print(vis1)

#marriage vs mental_well; married happiest, single less so, divorced the least
vis2<-ggplot(data=df, aes(x=married, y=mental_well))+
  geom_bar(stat="identity")

#print(vis2)

#group vs mental_well; Group B slightly above A
vis4<-ggplot(data=df, aes(x=group, y=mental_well))+
  geom_bar(stat="identity")

#group vs anxeity; A stays contained between 25-75% while B covers the whole range
vis4a<-ggplot(data=df, aes(x=group, y=anxiety))+
  geom_bar(stat="identity")

#anxiety distrub by group
vis4b<-ggplot(data=df, aes(x=anxiety, color=group))+
  geom_density()
#df$corgi<-as.factor(df$corgi)
vis4c<-ggplot(data=df, aes(x=mental_well, color=corgi))+
  geom_density()
vis4d<-ggplot(data=df, aes(x=mental_well))+
  geom_density()

#print(vis4a)
#print(vis4)
#print(vis4b)
#print(vis4c)
print(vis4d)

#sex vs mental_well; dudes rock
vis5<-ggplot(data=df, aes(x=sex, y=mental_well))+
  geom_bar(stat="identity")

#print(vis5)

#therapy vs mental_well; no therapy wins?
vis6<-ggplot(data=df, aes(x=therapy, y=mental_well))+
  geom_bar(stat="identity")


#print(vis6)

#income vs mental_well; kinda all over the place but generally higher income=better mental health
vis7<-ggplot(data=df, aes(x=income_k, y=mental_well))+
  geom_point(stat="identity")
#print(vis7)

vis8<-ggplot(data=df, aes(x=anxiety, color=hair_color))+
  geom_density()

#print(vis8)

vis8a<-ggplot(data=df, aes(x=corgi, color=anxiety))+
  geom_density()

#print(vis8a)

vis8b<-ggplot(data=df, aes(x=age))+
  geom_density()
#print(vis8b)
