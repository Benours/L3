prompt -- TP1 Q1 to Q17;

SELECT nom, prenom FROM ABONNE WHERE VILLE='MONTPELLIER';

SELECT * FROM EXEMPLAIRE WHERE code_pret='EMPRUNTABLE';

SELECT titre, categorie FROM LIVRE where categorie not in ('MEDECINE', 'SCIENCES', 'LOISIRS') order by categorie; 

select * from emprunt where d_ret_reel is null; 

select num_ex, d_emprunt from emprunt, abonne where abonne.num_ab=emprunt.num_ab and abonne.nom='DUPONT' and abonne.prenom='JEAN'; 

select numero, code_pret, etat from exemplaire, livre where livre.isbn=exemplaire.isbn and livre.titre='LE MUR'; 

select e2.numero from exemplaire e1, exemplaire e2 where e1.numero=4112 and e1.isbn=e2.isbn and e2.etat='BON' and e2.numero!=4112;

select * from livre where livre.isbn not in (select isbn from exemplaire);

select titre from livre left join exemplaire on livre.isbn=exemplaire.isbn where exemplaire.isbn is null;

select count(*) from emprunt e join abonne a on a.num_ab = e.num_ab where a.nom = 'RENARD' and a.prenom = 'ALBERT' and d_ret_reel is null;

select min(tarif*(1-reduc/100)) from abonne;

select num_ex from emprunt e join exemplaire ex on e.num_ex = ex.numero where ex.etat = 'ABIME';

select mot from mot_clef m where m.mot not in (select mot from caracterise);

select l.categorie, count(e.num_ab) from livre l join exemplaire ex on ex.isbn = l.isbn join emprunt e on e.num_ex = ex.numero join abonne a on a.num_ab = e.num_ab group by l.categorie;

select l.isbn, avg(ex.prix) from exemplaire ex join livre l on ex.isbn = l.isbn group by l.isbn having count(ex.isbn)>2;

select l.titre from livre l join caracterise c on c.isbn = l.isbn where c.isbn = '0_8_7707_2' and c.mot in (select mot from caracterise where isbn = '0_8_7707_2');

select l.categorie from livre l join exemplaire ex on ex.isbn = l.isbn join emprunt e on e.num_ex = ex.numero group by l.categorie having count(distinct e.num_ab) = (select count(distinct num_ab) from abonne);

prompt -- TP2 Q1 to Q18;

prompt --Q1;

alter table abonne add date_nai date;
--alter table abonne modify age numeric check (age in (date(year(now())) - date(year(date_nai))));
alter table abonne add type_ab varchar(20) check (type_ab in ('ADULTE', 'ENFANT'));
alter table abonne add cat_ab varchar(20) check (cat_ab in ('REGULIER', 'OCCASIONNEL', 'A PROBLEME', 'EXCLU'));
