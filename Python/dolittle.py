def mult_matrix(M, N):
    # N행렬을 전치행렬로
    Nt = [[N[j][i] for j in range(len(N))] for i in range(len(N[0]))]
    # 행렬 곱셈을 계산하기위한 중첩 목록 이해
    return [[sum(el_m * el_n for el_m, el_n in zip(row_m, col_n)) for col_n in Nt] for row_m in M]

def pivot_matrix(M):
    # Doolittle의 방법에서 사용되는 M에 대한 피벗 행렬을 반환합니다
    m = len(M)

    # 부동 소수점 값으로 단위 행렬 만들기
    id_mat = [[float(i ==j) for i in range(m)] for j in range(m)]

    # 다음의 가장 큰 요소가되도록 단위 행렬을 재정렬하십시오
    # M의 각 열은 M의 대각선에 배치됩니다.
    for j in range(m):
        row = max(range(j, m), key=lambda i: abs(M[i][j]))
        if j != row:
            # 행 바꾸기
            id_mat[j], id_mat[row] = id_mat[row], id_mat[j]

    return id_mat

def lu_decomposition(A,flag):
    #A의 LU 분해를 수행합니다 (정사각형이어야 함). PA = LU로. 이 함수는 P, L 및 U를 반환합니다
    n = len(A)

    # L과 U에 대한 제로 행렬 만들기
    L = [[0.0] * n for i in range(n)]
    U = [[0.0] * n for i in range(n)]

    # 피벗 행렬 P와 다중 행렬 PA 만들기
    if flag == 1:
       P = pivot_matrix(A)
#    P = [[float(i == j) for i in range(n)] for j in range(n)]
    else:
        P = [[float(i == j) for i in range(n)] for j in range(n)]
    PA = mult_matrix(P, A)

    # LU 분해 수행
    for j in range(n):
        # L의 모든 대각선 항목은 단일로 설정됩니다
        L[j][j] = 1.0

        # LaTeX: u_{ij} = a_{ij} - \sum_{k=1}^{i-1} u_{kj} l_{ik}
        for i in range(j+1):
            s1 = sum(U[k][j] * L[i][k] for k in range(i))
            U[i][j] = PA[i][j] - s1

        # LaTeX: l_{ij} = \frac{1}{u_{jj}} (a_{ij} - \sum_{k=1}^{j-1} u_{kj} l_{ik} )
        for i in range(j, n):
            s2 = sum(U[k][j] * L[i][k] for k in range(j))
            L[i][j] = (PA[i][j] - s2) / U[j][j]


    return (P, L, U)

if __name__ == "__main__":

    A = [[1, 3, -1, 2], [5, 8, 1, -4], [-1, 1, 4, -1], [2, -4, -1, 6]]
    P, L, U = lu_decomposition(A,1)

    print('L=',L)
    print('U=',U)
    print('LU=',mult_matrix(L, U))
    print('P=',P)
    print('PLU=',mult_matrix(P, mult_matrix(L, U)))