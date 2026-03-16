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
library(ggdag)
library(dagitty)

df <- read_csv(file="C:\\Users\\abroek\\OneDrive - Chapman University\\Desktop\\2kool4\\CPSC 540\\Assignment 2\\hw2.csv", show_col_types = FALSE)
#df$married<-as.numeric(as.factor(df$married))
#df$sex<-as.numeric(as.factor(df$sex))
print(head(df))
#hw_dag <- dagify(
#  mental_well ~ corgi + married + sex  + anxiety + age,
#  married ~  age,
#  income ~ age + married + sex,
#  waived_insurance ~ income + married,
#  therapy ~ anxiety + waived_insurance + income + mental_well,
#  veggies_week ~ age + married + income,
#  hair_color ~ age ,
#  corgi ~ age,
#  anxiety ~ group + age + corgi,
#  exposure = "corgi",
#  outcome = "mental_well"
#  )

#Only thing to adjust for is age; which I think I already did
#adjust<-dagitty::adjustmentSets(hw_dag)
#print(adjust)


#Frequentist PE
mod1<-glm(mental_well~corgi+age+married+sex+hair_color+anxiety+age*hair_color, data=df)
print(summary(mod1))

#Coefficients:
#                Estimate Std. Error t value Pr(>|t|)    
#(Intercept)    -0.584628   0.399305  -1.464 0.143800    
#corgi           0.230066   0.069112   3.329 0.000937 ***
#age             0.090688   0.008991  10.086  < 2e-16 ***

#So frequentist PE is  0.230066

#Frequentist IE
#print(confint(mod1))

#                     2.5 %     97.5 %
#(Intercept)    -1.36725065  0.1979950
#corgi           0.09461007  0.3655224
#age             0.07306548  0.1083107
#marriedmarried  1.32093985  2.3706330
#marriedsingle  -0.31080651  0.8444021
#sexmale         2.06747170  2.8705483
#anxiety        -0.34010791 -0.2460147

#Worst case corgi has a 0.09461007 effect on mental well being per pet instance, and best case a 0.3655224 effect


p2<-c(prior("normal(0,5)", class="b"),
      #prior("gamma(25,10)", class="b", coef="age"),
      #prior("normal(5,1)", class="b", coef="corgi"),
      prior("student_t(3, 5.8, 3.3)", class="Intercept"),
      #prior("normal(0,5)", class = "sd", group = "corgi"),
      prior("student_t(3, 0, 3.3)", class="sigma"))
#Bayseian PE and IE
#m1<-brm(mental_well~corgi+married+sex+anxiety+hair_color+age+age*hair_color, 
#prior = p2, sample_prior = "yes", data=df, iter = 4000)
#print(get_prior(m1))
print(summary(m1))
#print(mcmc_trace(m1))
#bmod<-brm(mental_well~corgi+age+married+sex+anxiety, prior=p1, data=df)

m1|> pp_check()
#print(describe_prior(bmod))
yrep<-posterior_predict(m1, draws=500)

ppc_stat(df$mental_well, yrep, stat="mean", binwidth = 0.005)

#print(describe_posterior(m1))
#                 Estimate Est.Error l-95% CI u-95% CI Rhat Bulk_ESS Tail_ESS
#corgi              0.17      0.07     0.03     0.30   1.00    11430     6221
#Corgi petting has a 0.43 increase in mental_well scores with a worst case/best case rage of 0.06 to 0.98
#print(mcmc_areas(bmod, pars="b_corgi"))
#visb2<-mcmc_dens(bmod, pars=" sd_age__Intercept")
#print(visb2)

