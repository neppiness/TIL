def solve(row):
    global is_used, p_diag, n_diag, col_occ, count, N
    if row == N:
        count += 1
        return
    
    for col in range(N):
        p = col + row
        m = col - row + N
        if p_diag[p] or n_diag[m] or col_occ[col]:
            continue
        col_occ[col] = 1
        p_diag[p] = 1
        n_diag[m] = 1
        solve(row + 1)
        col_occ[col] = 0
        p_diag[p] = 0
        n_diag[m] = 0

if __name__ == "__main__":
    count = 0
    N = int(input())
    board = [[0] * N for _ in range(N)]

    col_occ = [0 for _ in range(N)]
    p_diag = [0 for _ in range(2*N)]
    n_diag = [0 for _ in range(2*N)]

    solve(0)
    print(count)
