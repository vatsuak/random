import numpy as np
from scipy import stats
def knn(k,features,labels, query):
    '''
        returns the label for the query sample 
        params:
            k: int
            features: dxn-dim feature matix with n training samples
            labels: n-dim vector giving the class number for each of the trainig samples
            query: the test sample whose class label is to be determined
    '''
    d,n = features.shape
    X = np.hstack((features,query))
    Y = np.vstack((labels,[0]))
    G = np.dot(np.transpose(X),X)
    one = np.ones((n+1,1))
    d = np.reshape(np.diag(G),[-1,1])
    D = np.dot(one,(np.linalg.norm(query))**2)-2*np.dot(np.transpose(X),query)+d
    index = np.argsort(D, axis=0)
    Y_nn = np.take_along_axis(Y,index,0)
    y_hat,_ = stats.mode(Y_nn[2:k+2])
    return y_hat