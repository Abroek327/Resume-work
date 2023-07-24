#Andrew Broek
#Last Modified: 7/24/2023
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from numpy import diff
from sklearn import linear_model


#lots of print statements commented out for testing purposes 

sample=input("Enter the sample number: ")

#get the data and filter out when the load is negative
df=pd.read_csv('Specimen '+str(sample)+'.csv')
df2=df.iloc[1:]
df2=df2.astype(float)
#print (df.head)
df2=df2[df2.Load>0]
#print(df2)

#get the dimensions of the dogbone in mm 
Width=float(input("Enter the Width of the sample in mm: "))
Height=float(input("Enter the Height of the sample in mm: "))
Length=70.00 #hardcoded as 70 since it's consistent for all samples
area=Width*Height

#name the exported file
outName= str(input("Enter the desired name of the exported file: ")) + '.csv'

#calculate Stress
df2['Stress']=""
for i in range (len(df2)):
    df2['Stress'].iloc[i]=df2['Load'].iloc[i]/area

#print(df2)

#calculate strain
df2['Strain']=""
for i in range (len(df2)):
    df2['Strain'].iloc[i]=df2['Displacement'].iloc[i]/Length
#print(df2)

#find strain at break and breakpoint
df3=df2.copy()
dydx=diff(df3['Stress'])/diff(df3['Strain'])
#print(dydx)
#plt.plot(dydx)
for i in range (len(dydx)):
    if dydx[i]<-10000 and i>100:
        #print(i)
        bPoint=i-1
        break
#print(bPoint)
#print(df3['Strain'].iloc[bPoint])

#find max stress 
maxStress=df3['Stress'].max()
for i in range (len (df3)):
    if df3['Stress'].iloc[i]==maxStress:
        maxIndex=i
        break
#print(maxIndex)
#print(maxStress)

#plot the stress strain curve
plt.plot(df2['Strain'],df2['Stress']) 
plt.xlabel('Strain')
plt.ylabel('Stress (MPa)')
plt.title('Stress vs Strain for Specimen '+str(sample))


#convert data to more usable floats, necessary for linear regression
df2['Strain'].dtype
df4=df2.copy()
df4['Strain']=pd.to_numeric(df4['Strain'])
df4['Stress']=pd.to_numeric(df4['Stress'])

#beginning of the linear regression 
n=1

X=df4['Strain'].iloc[0:200] 
Y=df4['Stress'].iloc[0:200]

#shape the data to fit into the linear regression model properly
X=X.values.reshape(-1,1)
Y=Y.values.reshape(-1,1)

#fit the data
reg1=linear_model.LinearRegression()
reg1.fit(X,Y)


slope=reg1.coef_ #get the slope of the first sample 
slp_arr=[] #create array to store all the slopes
slp_arr.append(slope)

#loop through decreasing the index by an increasing amount to get the maximum slope
while n<len(df4['Strain']):

    #repeat the same process as above
    X=df4['Strain'].iloc[0+n:200+n]
    Y=df4['Stress'].iloc[0+n:200+n]
   
    X=X.values.reshape(-1,1)
    Y=Y.values.reshape(-1,1)
    reg1=linear_model.LinearRegression()
    reg1.fit(X,Y)
    slope=reg1.coef_

    slp_arr.append(slope)
    n+=1 
    
#find the maximum slope from array 
max_slp=max(slp_arr)
yngs=(max_slp[0][0])

#Elongation at break
displacment=df2['Displacement'].iloc[bPoint]
fLength=Length+displacment
elongation=((fLength-Length)/Length)*100


#Output

#Youngs Modulus
print("Youngs Modulus:", format(yngs, '.3f'), "MPa",)
#Max Stress
print("Max Stress:",format(maxStress, '.3f'), "MPa")
#Strain at break
print("Strain at Break:",format(df3['Strain'].iloc[bPoint], '.3f'))
#Elongation at break
print("Elongation at Break:",format(elongation, '.2f'), "%")

#put results into a dataframe
df4['Results']=pd.Series([0,yngs,maxStress,df3['Strain'].iloc[bPoint],elongation])

#export to csv
df4.to_csv(outName,index=False)

#display stress/strain curve
plt.show()


