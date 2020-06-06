import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn import tree
from sklearn.neural_network import MLPClassifier
from sklearn.svm import LinearSVC
from sklearn.metrics import accuracy_score
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.model_selection import GridSearchCV

# Importando os dados
url = "https://archive.ics.uci.edu/ml/machine-learning-databases/00267/data_banknote_authentication.txt"
raw_data = pd.read_csv(url, sep=",", header=None)
raw_data.columns = ["variance", "skewness", "curtosis", "entropy", "class"]

# Estatísticas
print(raw_data.describe())
sns.pairplot(raw_data)
plt.show()

#separando em target e data
data = raw_data.iloc[:, 0:4].values
target = raw_data.iloc[:, 4].values

#como os dados são todos numéricos, não foi necessário fazer conversões para ter todos dados numéricos

#separando dados em treino e teste proporção 60/40
data_train, data_test, target_train, target_test = train_test_split(data, target, test_size = 0.40, random_state = 10)

#Classificador K-NN
# 10-fold CrossValidation
param_grid = { 'n_neighbors': [5, 10, 15, 20] }
grid = GridSearchCV(KNeighborsClassifier(), 
        param_grid, cv=10)
grid.fit(data, target)
print("Melhores Parâmetros KNN:" , grid.best_params_)

# Cálculo Acurácia
knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(data_train, target_train)
predict = knn.predict(data_test)
soma1 = 100*accuracy_score(target_test, predict)
print("Score KNN: ", 100*accuracy_score(target_test, predict))

# Naive CBayes
# Naice CBayes não tem parâmetros para otimizar
ncb = GaussianNB()
ncb.fit(data_train, target_train)
predict = ncb.predict(data_test)
soma2 = 100*accuracy_score(target_test, predict)
print("Score Naive CBayes: ", 100*accuracy_score(target_test, predict, normalize=True))

# CART - Classification and Regression Tree (Árvore de Decisão)
# 10-fold CrossValidation
md = np.arange(1, 20)
ms = np.arange(10, 20)
param_grid ={
    'max_depth': md,
    'min_samples_split': ms,
}
grid = GridSearchCV(tree.DecisionTreeClassifier(random_state=1), param_grid=param_grid, cv=10, 
    scoring = 'accuracy', n_jobs=-1)
grid.fit(data, target)
print("Melhores Parâmetros CART:", grid.best_params_)

# Cálculo Acurácia
cart = tree.DecisionTreeClassifier(random_state=1, min_samples_split = 10, max_depth = 17)
cart.fit(data_train, target_train)
predict = cart.predict(data_test)
soma3 = 100*accuracy_score(target_test, predict)
print("Score CART: ", 100*accuracy_score(target_test, predict))

# MLP
# 10-fold CrossValidation
# Essa parte do código demora para executar
param_grid = {
        'random_state':[0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
        }

grid = GridSearchCV(MLPClassifier(),
        param_grid=param_grid, cv=10)
grid.fit(data, target)
print("Melhores Parâmetros MPL:", grid.best_params_)
################################################

# Cálculo Acurácia
mlp = MLPClassifier(hidden_layer_sizes=(50,25,10), max_iter=1000,activation = 'relu',solver='adam',random_state=0)
mlp.fit(data_train, target_train)
predict = mlp.predict(data_test)
soma4 = 100*accuracy_score(target_test, predict)
print("Score MLP: ", 100*accuracy_score(target_test, predict))

# Linear SVC (SVM)
# 10-fold CrossValidation
param_grid = {
        'random_state':[0,1,2,3,4,5,6,7,8,9], 
        'max_iter':[150000]}

grid = GridSearchCV(LinearSVC(), param_grid=param_grid, cv=10)
grid.fit(data, target)
print("Melhores Parâmetros LinearSVC:", grid.best_params_)

# Cálculo Acurácia
svc = LinearSVC(random_state=0, max_iter=150000)
svc.fit(data_train, target_train)
predict = svc.predict(data_test)
soma5 = 100*accuracy_score(target_test, predict, normalize=True)
print("Score LinearSVC: ", 100*accuracy_score(target_test, predict, normalize=True))

print("Soma Total: ", soma1+soma2+soma3+soma4+soma5)
