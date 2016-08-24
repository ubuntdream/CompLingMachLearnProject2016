###############################################################################
# Alexander Diegel
# Project: Mia
# 15.08.2016
###############################################################################
import pandas as pd
import numpy as np

#SVM as classifier method with kernels maybe?
from sklearn import metrics,svm, cross_validation

data =pd.read_csv('save.csv',sep=";", header = 0)
tdata= pd.read_csv('save.csv',sep=";", header=0)

X=data.ix[:,3:7]


#Preprocessing
lierlabel = (X.ix[:,1] != X.ix[:,2]).astype(int)

input = data.ix[:,[3,4,6]]

#Y= data.ix[:,3]

#XT = tdata.ix[0:500,[0,3:7]]
#YT = tdata.ix[0:500,3]

# maybe play with parameters. rbf-kernel is gaussian kernel ->very powerful
# C= inverse of punishing parameter
model = svm.SVC(C=5, kernel='rbf', shrinking=True, tol=1e-4)
model.fit(input.ix[0:5000,:],lierlabel.ix[0:5000])
predictions = model.predict(input.ix[0:5000,:])

# No CV but 0-1 Loss
loss = metrics.zero_one_loss(lierlabel.ix[0:5000],predictions, normalize=True, sample_weight=None)

# Testdata
testpredictions = model.predict(input.ix[5000:5500,:])

testLoss = metrics.zero_one_loss(lierlabel.ix[5000:5500],testpredictions, normalize=True, sample_weight=None)

# Cross val with Accuracy score
result = cross_validation.cross_val_score(model, input.ix[5000:5500,:], lierlabel.ix[5000:5500], scoring='accuracy', cv=10).mean()


#%%
fPfN = (testpredictions != lierlabel.ix[5000:5500]).astype(int)
res0 = pd.concat([fPfN, input.ix[5000:5500,:]], axis=1)

res1 = res0[res0.ix[:,0]>0]


#r= result0[row,:]

