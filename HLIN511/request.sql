SELECT nom, prenom FROM ABONNE WHERE VILLE='MONTPELLIER';

SELECT * FROM EXEMPLAIRE WHERE code_pret='EMPRUNTABLE';

SELECT titre, categorie FROM LIVRE where categorie not in ('MEDECINE', 'SCIENCES', 'LOISIRS') order by categorie; 

select * from emprunt where d_ret_reel is null; 

select num_ex, d_emprunt from emprunt, abonne where abonne.num_ab=emprunt.num_ab and abonne.nom='DUPONT' and abonne.prenom='JEAN'; 

select numero, code_pret, etat from exemplaire, livre where livre.isbn=exemplaire.isbn and livre.titre='LE MUR'; 

select e2.numero from exemplaire e1, exemplaire e2 where e1.numero=4112 and e1.isbn=e2.isbn and e2.etat='BON' and e2.numero!=4112;

select * from livre where livre.isbn not in (select isbn from exemplaire);

select titre from livre left join exemplaire on livre.isbn=exemplaire.isbn where exemplaire.isbn is null;