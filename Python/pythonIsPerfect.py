
N = [[1,2,3,4],[5,6,7,8]]
print(N) # [[1, 2, 3, 4], [5, 6, 7, 8]
Nt = [[N[j][i] for j in range(len(N))] for i in range(len(N[0]))]
print(Nt) # [[1, 5], [2, 6], [3, 7], [4, 8]]
