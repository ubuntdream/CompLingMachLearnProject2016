###############################################################################
# Alexander Diegel
# Project: Mia
# 15.08.2016
###############################################################################
import pandas as pd
import numpy as np

#SVM as classifier method with kernels maybe?
from sklearn import metrics,svm, cross_validation

data =pd.read_csv('save_prim_10000.csv',sep=";", header = 0)
tdata= pd.read_csv('save_prim_500.csv',sep=";", header=0)

X=data.ix[:,3:7]

#Preprocessing
lierlabel = (X.ix[:,1] != X.ix[:,2]).astype(int)

data_input = data.ix[:,[3,4,6]]
test_input = tdata.ix[:,[3,4,6]]

Y= tdata.ix[:,3:7]
tlierlabel = (Y.ix[:,1] != Y.ix[:,2]).astype(int)

#Y= data.ix[:,3]

#XT = tdata.ix[0:500,[0,3:7]]
#YT = tdata.ix[0:500,3]

# maybe play with parameters. rbf-kernel is gaussian kernel ->very powerful
# C= inverse of punishing parameter
model = svm.SVC(C=2.3, kernel='rbf', shrinking=True, tol=1e-4)
model.fit(data_input,lierlabel)
predictions = model.predict(data_input)

# No CV but 0-1 Loss
loss = metrics.zero_one_loss(lierlabel,predictions, normalize=True, sample_weight=None)

# Testdata
testpredictions = model.predict(test_input)

testLoss = metrics.zero_one_loss(tlierlabel,testpredictions, normalize=True, sample_weight=None)

# Cross val with Accuracy score
result = cross_validation.cross_val_score(model, test_input, tlierlabel, scoring='accuracy', cv=8).mean()

fPfN = (testpredictions != tlierlabel).astype(int)
res0 = pd.concat([fPfN, test_input], axis=1)

res1 = res0[res0.ix[:,0]>0]

#r= result0[row,:]

# Calculate how SVM differentiate lier
t_combi =pd.read_csv('all_combi.csv',sep=";", header = 0)

combipredictions = model.predict(t_combi)


#t1 = t1.reshape(21,21)

# Calculate the quality of the KI
data_look = data.ix[:,7]
wrong_look = (lierlabel != data_look).astype(int)
wrong = pd.concat([lierlabel, data_look, wrong_look], axis=1).as_matrix()
wrong_look = list(wrong_look)
print(100.0*wrong_look.count(1)/len(wrong))