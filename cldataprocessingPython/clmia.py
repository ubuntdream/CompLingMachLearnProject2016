###############################################################################
# Alexander Diegel
# Project: Mia
# 15.08.2016
###############################################################################
import pandas as pd
import numpy as np

#SVM as classifier method with kernels maybe?
from sklearn import metrics,svm, cross_validation

data =pd.read_csv('train.csv',sep=";")
tdata= pd.read_csv('test.csv',sep=";")

X=data.ix[:,0:3]
Y= data.ix[:,3]

XT = tdata.ix[:,0:3]
YT = data.ix[:,3]

# maybe play with parameters. rbf-kernel is gaussian kernel ->very powerful
model = svm.SVC(C=2, kernel='rbf', shrinking=True, tol=1e-4)
model.fit(X,Y)

predictions = model.predict(X)

# No CV but 0-1 Loss
loss = metrics.zero_one_loss(Y,predictions, normalize=True, sample_weight=None)

# Testdata
testLoss = metrics.zero_one_loss(Y,model.predict(XT), normalize=True, sample_weight=None)

# Cross val with Accuracy score
result = cross_validation.cross_val_score(model, X, Y, scoring='accuracy', cv=10).mean()