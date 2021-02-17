-- DISTINCT를 사용한 중복 데이터 제거
SELECT DISTINCT deptno FROM emp;

-- GROUP BY를 사용한 중복 데이터 제거
SELECT deptno FROM emp GROUP BY deptno;