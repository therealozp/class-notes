define an elliptic curve as specified, $p  = 37, a = -3, b= 10$
![[Pasted image 20251104220408.png]]
after computing the generator point $G = (0:11:1)$, note that $-G=(0:26:1)$. at this point, we obtain our random secret key 7, and public key $(9:34:1)$.

![[Pasted image 20251104221045.png]]
after computing the curve point $C=(2:30:1)$, we are then able to derive our signature $r=2$, and $s=13$.
- the signature is the point $(r, s)=(2:13)$

the verification step takes place at the end, as we compute $CP$. we successfully confirm that $C = CP$.