###############################################################################
# Alexander Diegel
# Project: Mia
# 28.08.2016
###############################################################################"""

import pandas as pd
import numpy as np
#SVM as classifier method with kernels
from sklearn import metrics,svm, cross_validation
import os

#Load all datasets. You can adapt this path. Files are in our git-repo.
#Reduce dataset to max 10000 for computational reasons
os.chdir('/home/alex/Schreibtisch/data')
data_stat = pd.read_csv('statisticki1mio.csv',sep=";", header = 0).ix[1:10000,:]
data_prim = pd.read_csv('primitiveki1mio.csv', sep=";", header=0).ix[1:10000,:]

data_svm1 = pd.read_csv('svm1ki5K.csv', sep=";", header=0)
data_svm2 = pd.read_csv('svm2ki5K.csv', sep=";", header=0)
data_svm3 = pd.read_csv('svm3ki5K.csv', sep=";", header=0)
data_svm4 = pd.read_csv('svm4ki5K.csv', sep=";", header=0)
#%%
data_original = data_svm4
#switch between sets
#data_svm3
#data_svm2
#data_svm1
#data_prim
#data_stat 

data = data_original.ix[:,[3,4,6]]
label = (data_original['NewValue']!= data_original['RandomValue']).astype(int)
#Generate testdata and traindata, using 30% for testing
traindata, testdata, trainlabel, testlabel = cross_validation.train_test_split(data,label, test_size=0.3, random_state=7)


#automatisieren mit 40%testdaten
#leave first row out because of uninitialised lastvalue (not under windows?)
#use columns newGame, NewValue and LastValue
#traindata = data.ix[1:10000,[3,4,6]]
#1) Predict if Player is a liar or tells the truth
#trainlabel= (data['NewValue']!= data['RandomValue']).ix[1:10000].astype(int)

#testdata = data.ix[2001:2500,[3,4,6]]
#testlabel = (data['NewValue']!= data['RandomValue']).ix[2001:2500].astype(int)

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
    s = "C="+repr(c)+" result="+ repr(result)

    if result > lastresult2:
        cmax2=c
        lastresult2=result
    print(s)
s="Maximal value is for c="+repr(cmax2)
print(s)

# Using testset with estimated parameter    
model = svm.SVC(C=cmax2, kernel='rbf', shrinking=True, tol=1e-4)
testresult = cross_validation.cross_val_score(model, testdata, testlabel, scoring='accuracy', cv=10, n_jobs=6).mean()
s = "Testresult= " +repr(testresult)
print(s)

#How many samples until good result is achieved 
trainset = 100
eps = 1
tempresult = 0

#Plotten! Reihe aufnehmen.
print("Convergence")
while eps> 1e-4 and trainset<data.shape[0]:
    td = data.ix[1:trainset,:]
    tl= (data_original['NewValue']!= data_original['RandomValue']).ix[1:trainset].astype(int)
    model = svm.SVC(C=1, kernel='rbf', shrinking=True, tol=1e-5)
    model.fit(traindata,trainlabel)
    result = cross_validation.cross_val_score(model, td, tl, scoring='accuracy', cv=10, n_jobs=6).mean()
    s = "trainset="+repr(trainset)+" result="+ repr(result)    
    print(s)    
    eps = abs(result-tempresult)
    tempresult = result
    trainset+=500

# Quality of original KI?
print("Quality of KI")
x = (data_original['NewValue']!= data_original['RandomValue']) == (data_original['look'])
c = x.tolist().count(True)
s = "Original KI recognized: " + repr(c/(x.size))
print(s)


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
