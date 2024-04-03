-- 코드를 입력하세요
SELECT PT_NAME, PT_NO, GEND_CD, AGE, NVL(TLNO, 'NONE') AS TLNO
FROM PATIENT
WHERE GEND_CD LIKE 'W' AND AGE <= 12
ORDER BY AGE DESC, PT_NAME;