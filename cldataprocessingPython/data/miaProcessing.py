###############################################################################
# Alexander Diegel
# Project: Mia
# 28.08.2016
###############################################################################"""

import pandas as pd
import numpy as np
#SVM as classifier method with kernels
from sklearn import metrics,svm, cross_validation

data_stat =pd.read_csv('statistic10mio.csv',sep=";", header = 0)
data_prim = pd.read_csv('primitive10mio.csv', sep=";", header=0)

#%%
data = data_prim #switch between sets

#leave first row out because of uninitialised lastvalue (not under windows?)
#use columns newGame, NewValue and LastValue
traindata = data.ix[1:10000,[3,4,6]]
#1) Predict if Player is a liar or tells the truth
trainlabel= (data['NewValue']!= data['RandomValue']).ix[1:10000].astype(int)

testdata = data.ix[2001:2500,[3,4,6]]
testlabel = (data['NewValue']!= data['RandomValue']).ix[2001:2500].astype(int)

# do crossvalidation for checking parameters part 1
cvalues=[0.001, 0.01, 0.1, 1, 10, 100, 1000]
cmax = -1
lastresult = 0

for c in cvalues:
    model = svm.SVC(C=c, kernel='rbf', shrinking=True, tol=1e-4)
    model.fit(traindata,trainlabel)
    result = cross_validation.cross_val_score(model, traindata, trainlabel, scoring='accuracy', cv=10, n_jobs=6).mean()
    s = "C="+repr(c)+" result="+ repr(result)

    if result > lastresult:
        cmax=c
        lastresult=result
    print(s)

#Output statistic-ki
#C=0.001 result0.8768001506001506
#C=0.01 result0.8768001506001506
#C=0.1 result0.8768001506001506
#C=1 result0.87840064970064957 --> highest accuracy in training
#C=10 result0.87660174940174951
#C=100 result0.87600184970184958
#C=1000 result0.87680215000214989

# do crossvalidation for checking parameters part 2
set1=np.arange(cmax/10,cmax, cmax/10)  
set2 = np.arange(cmax,cmax*10, cmax)  
cvalues2 =np.concatenate( (set1,set2) ,axis=0)

cmax2 = -1;
lastresult2=0;

for c in cvalues2:
    model = svm.SVC(C=c, kernel='rbf', shrinking=True, tol=1e-4)
    model.fit(traindata,trainlabel)
    result = cross_validation.cross_val_score(model, traindata, trainlabel, scoring='accuracy', cv=10, n_jobs=6).mean()
    s = "C="+repr(c)+" result"+ repr(result)

    if result > lastresult2:
        cmax2=c
        lastresult2=result
    print(s)
s="Maximal value is for c="+repr(cmax2)
print(s)

#Output statistic-ki
#C=0.1 result0.8768001506001506
#C=0.2 result0.87760025090025096
#C=0.3 result0.87980015100015108 -->surprising result!
#C=0.5 result0.87860135060135069
#C=0.7 result0.87880145010145017
#C=1 result0.87840064970064957
#C=2 result0.87790054980054977
#C=3 result0.87710144930144929
    

# Using testset with estimated parameter    
model = svm.SVC(C=cmax2, kernel='rbf', shrinking=True, tol=1e-4)
testresult = cross_validation.cross_val_score(model, testdata, testlabel, scoring='accuracy', cv=10, n_jobs=6).mean()
s = "Testresult= " +repr(testresult)
print(s)
#Statisticki
#(Testresult= 0.85210804321728695 --C=1)
#Testresult= 0.8779903961584633 -- C=0.3

#Primitiveki C=1
#Testresult= 0.81217046818727501
#%%
#How many samples until good result is achieved 
#@FALKO wie können wir das besser machen bzw dass es überhaupt sinnvoll tut?
trainset = 250
eps = 1
tempresult = 0

while eps> 1e-4:
    traindata = data.ix[1:trainset,[3,4,6]]
    trainlabel= (data['NewValue']!= data['RandomValue']).ix[1:trainset].astype(int)
    model = svm.SVC(C=0.3, kernel='rbf', shrinking=True, tol=1e-6)
    model.fit(traindata,trainlabel)
    result = cross_validation.cross_val_score(model, traindata, trainlabel, scoring='accuracy', cv=10, n_jobs=6).mean()
    s = "trainset="+repr(trainset)+" result"+ repr(result)    
    print(s)    
    eps = abs(result-tempresult)
    tempresult = result
    trainset+=1000
#%%





#%%
#X=data.ix[:,3:7]
#
##Preprocessing
#lierlabel = (X.ix[:,1] != X.ix[:,2]).astype(int)
#
#data_input = data.ix[:,[3,4,6]]
#test_input = tdata.ix[:,[3,4,6]]
#
#Y= tdata.ix[:,3:7]
#tlierlabel = (Y.ix[:,1] != Y.ix[:,2]).astype(int)
#
##Y= data.ix[:,3]
#
##XT = tdata.ix[0:500,[0,3:7]]
##YT = tdata.ix[0:500,3]
#
## maybe play with parameters. rbf-kernel is gaussian kernel ->very powerful
## C= inverse of punishing parameter
#model = svm.SVC(C=5, kernel='rbf', shrinking=True, tol=1e-4)
#model.fit(data_input,lierlabel)
#predictions = model.predict(data_input)
#
## No CV but 0-1 Loss
#loss = metrics.zero_one_loss(lierlabel,predictions, normalize=True, sample_weight=None)
#
## Testdata
#testpredictions = model.predict(test_input)
#
#testLoss = metrics.zero_one_loss(tlierlabel,testpredictions, normalize=True, sample_weight=None)
#
## Cross val with Accuracy score
#result = cross_validation.cross_val_score(model, test_input, tlierlabel, scoring='accuracy', cv=10).mean()
#
#
#fPfN = (testpredictions != tlierlabel).astype(int)
#res0 = pd.concat([fPfN, test_input], axis=1)
#
#res1 = res0[res0.ix[:,0]>0]
#
##r= result0[row,:]
#
## Calculate how SVM differentiate lier
#t_combi =pd.read_csv('all_combi.csv',sep=";", header = 0)
#
#combipredictions = model.predict(t_combi)
#
#
##t1 = t1.reshape(21,21)
#
## Calculate the quality of the KI
#data_look = data.ix[:,7]
#wrong_look = (lierlabel != data_look).astype(int)
#wrong = pd.concat([lierlabel, data_look, wrong_look], axis=1).as_matrix()
#wrong_look = list(wrong_look)
#print(100.0*wrong_look.count(1)/len(wrong))
