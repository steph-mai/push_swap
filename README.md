*This project has been created as part of the 42 curriculum by marberge, stmaire.*             

---

<div align="center">
<br>
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTQPzuYKu7n0cWUYa5Kbg0_LrlEQAIURWeo9A&s" alt="42 Logo" width="400" />

  <br>
</div>

# push_swap

![Language](https://img.shields.io/badge/Language-C-blue)
![Bonus](https://img.shields.io/badge/Bonus-No-red)
![Grade](https://img.shields.io/badge/Grade-100%2F100-brightgreen)
![Tag](https://img.shields.io/badge/Algorithm-grey)
![Tag](https://img.shields.io/badge/Complexity-grey)
![Tag](https://img.shields.io/badge/Optimization-grey)


**Push_swap** est un projet d'algorithmique avancé qui consiste à trier des données sur une pile (stack), avec un jeu d'instructions limité et en un nombre de coups strictement optimisé.

Le défi principal n'est pas seulement de trier, mais de le faire avec une **efficacité mathématique**. Le programme ne se contente pas d'appliquer une méthode unique : il est conçu pour être **intelligent et adaptatif**, analysant les données avant d'agir.

---

## 1. Description

<details>
<summary><strong>🎮 Les Règles du Jeu</strong></summary>

Le projet fonctionne avec deux piles : **Stack A** et **Stack B**.

1.  **État Initial :**
    * **Stack A** : Contient une liste aléatoire d'entiers (positifs ou négatifs), sans doublons.
    * **Stack B** : Est vide.
2.  **Objectif :**
    * Trier les nombres de la **Stack A** par ordre croissant (le plus petit au sommet).
    * La **Stack B** doit être vide à la fin de l'exécution.
3.	**Les opérations disponibles :**

	* **🔄 Swap (Échange)**

* `sa` **(swap a)** : Échange les deux premiers éléments au sommet de la pile `a`. (Ne fait rien s'il n'y a qu'un ou aucun élément).
* `sb` **(swap b)** : Échange les deux premiers éléments au sommet de la pile `b`. (Ne fait rien s'il n'y a qu'un ou aucun élément).
* `ss` : Effectue `sa` et `sb` en même temps.

	* **📤 Push (Pousser)**

* `pa` **(push a)** : Prend le premier élément au sommet de `b` et le place sur `a`. (Ne fait rien si `b` est vide).
* `pb` **(push b)** : Prend le premier élément au sommet de `a` et le place sur `b`. (Ne fait rien si `a` est vide).

	* **⬆️ Rotate (Rotation)**

* `ra` **(rotate a)** : Décale d'une position vers le haut tous les éléments de la pile `a`. (Le premier élément devient le dernier).
* `rb` **(rotate b)** : Décale d'une position vers le haut tous les éléments de la pile `b`. (Le premier élément devient le dernier).
* `rr` : Effectue `ra` et `rb` en même temps.

	* **⬇️ Reverse Rotate (Rotation Inverse)**

* `rra` **(reverse rotate a)** : Décale d'une position vers le bas tous les éléments de la pile `a`. (Le dernier élément devient le premier).
* `rrb` **(reverse rotate b)** : Décale d'une position vers le bas tous les éléments de la pile `b`. (Le dernier élément devient le premier).
* `rrr` : Effectue `rra` et `rrb` en même temps.

4. **🚀 Le Défi de la Complexité**

Pour atteindre le grade "Excellent", ce programme implémente une **stratégie adaptative**. Avant de trier, il calcule le **taux de désordre** de la liste pour sélectionner l'algorithme le plus performant en fonction du désordre et de la taille de la liste à trier.

</details>

<details>
<summary><strong>⚡ Modes de Fonctionnement</strong></summary>



Afin de faciliter le contrôle des performances, le programme intègre plusieurs modes d'exécution activables via des drapeaux (flags):

* **Mode Automatique (Par défaut)** : Le programme est autonome. Il scanne la pile et choisit la meilleure stratégie pour minimiser les coups.
* **Modes Forcés (`--simple`, `--medium`, `--complex`)** : Ces options permettent de désactiver l'intelligence artificielle du programme pour forcer l'utilisation d'un algorithme spécifique, quelle que soit la taille de la liste. C'est idéal pour vérifier la robustesse de chaque méthode individuellement.
* **Mode Benchmark (`--bench`)** : Transforme le programme en outil d'analyse scientifique. En plus de trier, il calcule et affiche des statistiques précises sur la **sortie d'erreur** (taux de désordre, stratégie utilisée, compteurs d'opérations détaillés), permettant une validation rigoureuse sans perturber le checker.

</details> 

## 2. Instructions

<details>
<summary><strong>🔧 Compilation</strong></summary>




Le projet est écrit en C et utilise un `Makefile` pour la compilation. Assurez-vous d'avoir `gcc` et `make` installés sur votre machine.
Cette commande génère l'exécutable `push_swap`.

```bash
    make
```

---

</details>

<details>
<summary><strong>🚀 Exécution</strong></summary>


Le programme prend en argument une liste d'entiers à trier.

**Syntaxe de base :**
```bash
./push_swap [NOMBRES...]
```
**Exemple simple :**
```bash
./push_swap 42 1337 -21 0 5
```
Utilisation avec une variable (Recommandé) : Pour tester facilement la même liste avec le programme et le checker.
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG
```

</details>

<details>
<summary><strong>🚩 Options & Drapeaux</strong></summary>


Vous pouvez ajouter un drapeau **avant** la liste de nombres pour modifier le comportement du programme.

#### 1. Forcer une stratégie spécifique
Par défaut, le programme est adaptatif. Pour tester manuellement un algorithme précis :

##### Force l'algorithme quadratique (Simple)
```bash
./push_swap --simple 4 2 5 1
```
##### Force l'algorithme par chunks (Moyen)
```bash
push_swap --medium $ARG
```
##### Force l'algorithme optimisé (Complexe)
```bash
./push_swap --complex $ARG
```
#### 2. Activer le mode Benchmark
Pour obtenir les statistiques de tri (désordre, complexité, compteurs) sur la sortie d'erreur (`stderr`) :

```bash
./push_swap --bench $ARG
```

</details>

<details>
<summary><strong>✅ Vérification (Checker)</strong></summary>


Le programme est conçu pour être utilisé en "pipe" avec le binaire de vérification (`checker_linux` ou votre propre bonus checker).

**Commande standard :**
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```
*La sortie doit afficher `OK` si le tri est valide.*

**Vérification avec le Benchmark actif :**
Comme le benchmark écrit sur la sortie d'erreur (`stderr`), il ne perturbe pas le checker qui lit uniquement la sortie standard (`stdout`) :

```bash
./push_swap --bench $ARG | ./checker_linux $ARG
```

</details> 

<details>
<summary><strong>🧹 Nettoyage</strong></summary>



* **`make clean`** : Supprime les fichiers objets (`.o`).
* **`make fclean`** : Supprime les fichiers objets et l'exécutable `push_swap`.
* **`make re`** : Recompile tout depuis zéro.
</details>

## 3. Ressources et références 

<details>
<summary><strong>🧠 Algorithmes & Stratégies</strong></summary>

Voici une sélection de ressources techniques pour comprendre les algorithmes implémentés et les outils utilisés pour valider le projet.

* **[Push_swap — A journey to find the optimal sorting algorithm](https://medium.com/nerd-for-tech/push-swap-v2-comprehensive-guide-434f86d60661)** : Explication du **Radix Sort** (tri par base), l'alternative mathématique binaire pour garantir une complexité $O(n \log n)$.
* **[Big O Cheat Sheet](https://www.bigocheatsheet.com/)** : Le tableau de référence pour visualiser graphiquement les différences de performance entre $O(n^2)$ (Simple), $O(n\sqrt{n})$ (Moyen) et $O(n \log n)$ (Complexe).

* **[Wikipedia : Tri par insertion](https://fr.wikipedia.org/wiki/Tri_par_insertion)**
* **[Wikipedia : Tri par selection](https://fr.wikipedia.org/wiki/Tri_par_selection)**
* **[Wikipedia : Tri à bulles](https://fr.wikipedia.org/wiki/Tri_%C3%A0_bulles)**
* **[Wikipedia : Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort)**
* **[Wikipedia : Radix sort](https://fr.wikipedia.org/wiki/Tri_par_base)**
* **[Wikipedia : Merge sort](https://fr.wikipedia.org/wiki/Tri_fusion)**
* **[Wikipedia : Quick sort](https://fr.wikipedia.org/wiki/Tri_rapide)**
* **[Wikipedia : Heap sort](https://fr.wikipedia.org/wiki/Tri_par_tas)**

</details>

<details>
<summary><strong>🛠️ Outils de Test & Visualisation</strong></summary>


* **[push_swap_visualizer (o-reo)](https://github.com/o-reo/push_swap_visualizer)** : Un outil graphique indispensable pour **voir** les piles bouger en temps réel. Il permet de comprendre visuellement la logique de tri et de débugger les boucles infinies.
* **[push_swap_tester (SimonCROS)](https://github.com/SimonCROS/push_swap_tester)** : Un script de benchmark complet pour lancer des milliers de tests aléatoires, vérifier la gestion des erreurs et calculer la moyenne de coups. Essentiel pour calibrer le mode adaptatif.

</details>

<details>
<summary><strong>🤖 Utilisation de l'IA</strong></summary>


Dans le cadre de ce projet, l'intelligence artificielle a été utilisée comme un outil d'assistance complémentaire aux recherches traditionnelles. Elle est intervenue sur trois axes principaux :
* **Support Théorique :** Aide à la vulgarisation et à la compréhension de concepts algorithmiques avancés (calcul de complexité temporelle/spatiale, notation Big O) et mathématiques (calcul du taux de désordre d'une liste).
* **Génération de Tests :** Création de jeux de données spécifiques, notamment des séries de nombres respectant des pourcentages de désordre précis, pour éprouver la robustesse des algorithmes de tri.
* **Débogage :** Assistance à l'analyse de code pour l'identification d'erreurs logiques et la résolution de problèmes de gestion de mémoire (segmentation faults).
</details>

## 4. Stratégies Algorithmiques & Complexité

<!-- Pour résoudre efficacement le problème de tri quelle que soit la taille de l'entrée, ce projet implémente trois approches algorithmiques distinctes, allant de la méthode naïve à la plus optimisée, conformément aux exigences du sujet. -->

<details>
<summary><strong>🟢 L'Algorithme Simple O(n²)</strong></summary>

* **Cible :** Petites piles (3 à ~20 valeurs).

* **Strategies possibles (quelques exemples) :**

-- **Bubble sort** : On parcourt la pile. Si le nombre du haut est plus grand que le suivant, on les échange (sa). Sinon, on passe au suivant (ra). Après un premier parcours complet du tableau, le plus grand élément est forcément en fin de tableau, à sa position définitive. On recommence à parcourir le tableau tant que tout n'est pas trié. Cet algorithme consomme énormément de mouvements (sa, ra en boucle). 

-- **Tri par insertion (Insertion Sort) :** On prend le nombre en haut de `a` (pb), et on l'insère à la bonne place dans la pile `b` (qui est toujours triée). À la fin, on remet tout dans `a`. Solution complexe à coder car, vu qu'elle insère au bon endroit dans la pile, cela demande de calculer les coûts de rotation.

-- **Tri par Sélection :** L'algorithme parcourt la totalité de la pile `a` pour trouver le plus petit nombre (minimum), le pousse vers la pile `b`, et répète le processus jusqu'à ce que `a` soit vide. Très facile à coder. Coût élevé (~ n × n opérations), mais suffisamment efficace pour de très petites listes où la surcharge est minime.

-- **L'Extraction Min/Max (Extraction Method) :**
C'est une version plus "flexible" du tri par sélection, qui peut être utilisée pour optimiser les coups. Il s'agit de vider la pile `a`A le plus vite possible en enlevant les "extrêmes". La méthode : Regarder la pile `a`. Se demander : "Qui est le plus près du haut ? Le Minimum ou le Maximum ?" Si le Min est plus près : on le monte et pb (et on le laisse en haut de `b`). Si le Max est plus près : on le monte et pb (et on le met en bas de 'b' avec rb). La pile `b` est donc triée au fur et à mesure, mais on a économisé des rotations en choisissant le chemin le plus court (vers le Min ou vers le Max). NB : au delà de 3 nombres, cela ne fonctionne plus sans adaptations car `b` n'est plus trié...

</details>

<details>
<summary><strong>🟡 L'Algorithme Moyen O(n√n)</strong></summary>

* **Cible :** Piles moyennes (ex : 100 valeurs).

* **Stratégie :** **Chunk-based sorting (Tri par paquets)** 
* **Fonctionnement :**
	1.	On commence par indexer les valeurs en remplaçant les valeurs réelles par leur rang.
    1.  La pile est virtuellement divisée en plages de valeurs appelées "chunks". Le nombre de chunks est déterminé par la racine carrée du nombre total d'éléments (√n).
    2.  Au lieu de chercher un nombre précis (comme le minimum exact), l'algorithme cherche **n'importe quel** nombre appartenant au chunk actuel.
    3.  Une fois poussés sur la pile `b`, les éléments sont grossièrement triés par groupes. Ils sont ensuite repoussés vers `a` avec un tri précis.
* **Pourquoi O(n√n) ?** Chercher "n'importe quel élément d'un chunk" est statistiquement bien plus rapide que de chercher un élément spécifique. On effectue `n` poussées, mais avec un coût de recherche réduit à `√n` en moyenne.

* **Variantes de cette stratégie (quelques exemples):**

-- **Block-based partitioning (Partitionnement par blocs)**
Variante du tri par paquets, cette approche se concentre sur la structure de la pile. Au lieu de définir des plages de valeurs strictes, on divise la pile initiale en segments ou "blocs" logiques. L'objectif est de déplacer des blocs entiers d'éléments vers la pile B en optimisant les mouvements. Une fois dans B, chaque bloc est considéré comme une sous-section indépendante, ce qui réduit la complexité de recherche du prochain élément à trier (on ne cherche que dans le bloc actif au sommet).

-- **Bucket sort adaptations (Adaptation du tri par seaux)**

Le tri par seaux classique distribue les éléments dans plusieurs contenants distincts. Dans Push_swap, n'ayant qu'une seule pile B, on adapte ce principe en empilant les "seaux" les uns sur les autres. On définit n​ intervalles de valeurs (les seaux). On parcourt la pile A et on envoie les éléments dans la pile B en les regroupant par intervalle. L'astuce réside dans la gestion de l'empilement dans B pour garder les seaux accessibles ou partiellement triés via des rotations judicieuses (rb).

-- **Range-based sorting strategies (Stratégies par intervalles dynamiques)**

C'est souvent l'évolution la plus performante du tri par paquets. Au lieu d'avoir des paquets fixes (ex: 1 à 20), on utilise une "fenêtre glissante" ou un intervalle dynamique (= le range). Si le nombre au sommet de A est compris dans l'intervalle [0, compteur + range] (compteur = nombre d'élements déjà pré-triés), on le pousse vers B. À chaque push, l'intervalle grandit ou se décale. Cette méthode lisse la distribution des nombres dans la pile B (souvent en forme de courbe de Gauss) et minimise les rotations nécessaires pour récupérer les éléments extrêmes lors de la phase finale. A la fin, les plus grands nombres (ceux qui sont rentrés en dernier) sont globalement vers le haut de la pile, et les plus petits (rentrés au début) sont vers le bas ou le milieu. Enfin, il reste à reconstruire la pile A à l'envers, en cherchant le maximum dans `b` qui a été pré-trié.

</details>

<details>
<summary><strong>🔴 L'Algorithme Complexe O(n log n)</strong></summary>


* **Cible :** Grandes piles (500+ valeurs).
* **Pourquoi O(n log n) ?**
    * En informatique, **log n** (logarithme en base 2) est la réponse à la question : **"Combien de fois puis-je couper ma liste en deux avant qu'il ne reste plus qu'un seul élément ?"**
    * Pour 500 nombres, la réponse est seulement 9 (log₂ 500 ≈ 9).
    * Au lieu de faire 500 tours de boucle (comme le tri simple), cet algorithme ne nécessite qu'environ 9 niveaux de division pour isoler et trier chaque nombre. C'est ce qui le rend exponentiellement plus rapide.

* **Stratégies possibles (quelques exemples) :**

-- **Radix sort adaptation (LSD or MSD) :** 
		
Contrairement aux tris classiques qui comparent les valeurs entre elles (a > b), le Radix trie les nombres en traitant leurs chiffres individuellement. 
Pour ce projet, il est possible d'utiliser une version binaire (Base 2) de l'algorithme, particulièrement adaptée aux opérations bit-à-bit :
Deux approches sont possibles :

LSD = Least Significant Digit (Chiffre le Moins Significatif).
    On commence par la droite (les unités, ou ici le bit 0).
    On remonte vers la gauche. 

MSD = Most Significant Digit (Chiffre le Plus Significatif).
    On commence par la gauche (les milliers, ou ici le bit le plus fort).
    On descend vers la droite.



<details>
<summary><strong> ➡️ Tableau comparatif LSD/MSD</strong></summary>

| Critère | LSD (Least Significant Digit) | MSD (Most Significant Digit) |
| :--- | :--- | :--- |
| **Logique** | De Droite à Gauche (Bit 0 $\rightarrow$ Bit Max) | De Gauche à Droite (Bit Max $\rightarrow$ Bit 0) |
| **Structure** | **Itératif** (Une simple boucle `for`) | **Récursif** (Nécessite des appels de fonctions imbriqués) |
| **Gestion des Piles** | On traite **toute** la pile A à chaque tour (A $\leftrightarrow$ B). | On doit gérer des **sous-portions** de piles isolées. |
| **Complexité Code** | ✅ **Très facile** (Idéal pour Push_swap). | ⚠️ **Difficile** (Gestion d'index et de récursivité complexe). |
| **Efficacité** | **Constante** (Le nombre de coups est prévisible). | **Variable** (Potentiellement plus rapide, mais dur à optimiser).

</details>

---

<br>

 
 Les valeurs réelles sont d'abord simplifiées par leur rang (de 0 à N-1). Cela permet de travailler avec des entiers positifs et contigus, réduisant la complexité. L'algorithme parcourt ensuite les nombres bit par bit, du moins significatif (droite) au plus significatif (gauche). Si le bit actuel est 0 : Le nombre est poussé vers la pile B. Si le bit actuel est 1 : Le nombre reste dans la pile A (rotation). Après avoir traité un bit pour toute la pile, le contenu de B est reversé dans A, et le cycle recommence pour le bit suivant.


-- **Merge sort adaptation using two stacks :** 

Le Merge Sort est l'exemple classique de l'approche algorithmique "Diviser pour régner" (Divide and Conquer). C'est un tri par comparaison très efficace, particulièrement adapté aux structures de données séquentielles comme les listes chaînées.
- Diviser : On coupe la pile principale en deux sous-piles égales (récursivement) jusqu'à obtenir des piles d'un seul élément.
- Régner : Une pile d'un seul élément est considérée comme triée.
- Combiner (Fusion) : C'est l'étape clé. On fusionne deux sous-piles triées pour en former une plus grande, en comparant à chaque fois les éléments au sommet pour insérer le plus petit (ou le plus grand) en premier.
- Performance : Il offre une complexité garantie de O(n log n) dans tous les cas (pire, moyen et meilleur), ce qui le rend très fiable.

Note pour Push_swap : Bien que très performant théoriquement, son implémentation avec seulement deux piles et des rotations demande une gestion rigoureuse pour simuler la division et la fusion sans accès aléatoire à la mémoire.

-- **Quick sort adaptation with stack partitioning :** 

La méthode consiste à placer un élément du tableau (appelé pivot) à sa place définitive, en permutant tous les éléments de telle sorte que tous ceux qui sont inférieurs au pivot soient à sa gauche et que tous ceux qui sont supérieurs au pivot soient à sa droite.

Cette opération s'appelle le partitionnement. Pour chacun des sous-tableaux, on définit un nouveau pivot et on répète l'opération de partitionnement. Ce processus est répété récursivement, jusqu'à ce que l'ensemble des éléments soit trié. 

-- **Heap sort adaptation :** 

Le tri par tas (Heap Sort) est un algorithme de comparaison efficace et en place qui structure les données sous forme d'un arbre binaire (appelé "tas" ou heap), généralement un Tas-Max où chaque nœud est supérieur à ses enfants. Le fonctionnement repose sur deux étapes clés : d'abord, on transforme le tableau entier en un tas pour que l'élément le plus grand se retrouve obligatoirement à la racine (au début du tableau) ; ensuite, on échange itérativement cette racine avec le dernier élément de la zone non triée, on réduit la taille du tas considéré, et on réorganise ("entasse") la structure pour faire remonter le nouveau maximum au sommet. Ce processus répété déplace progressivement les plus grands éléments vers la fin du tableau, garantissant un tri avec une complexité temporelle optimale de O(nlogn) dans tous les cas, sans nécessiter de mémoire supplémentaire importante.

-- **Binary indexed tree approaches :** 

Le BST sort (Binary Search Tree ou arbre de recherche binaire) recourt aussi aux arbres binaires mais la logique de rangement est différente : contrairement au heap sort où l'élément le plus grand est en haut, ici tout ce qui est plus petit doit aller à gauche, tout ce qui est plus grand doit aller à droite.
exemple :

<details><summary>➡️ Exemple : Tri par Arbre Binaire de Recherche (BST) 🌳</summary>

**Tableau initial :** `[4, 10, 3, 5, 1]`

#### Étape 1 : Construction de l'arbre (Insertion)
| Tour | Nombre | Comparaisons (Le Chemin) | Action finale |
| :---: | :---: | :--- | :--- |
| 1 | **4** | *(L'arbre est vide)* | Devient la **Racine**. |
| 2 | **10** | 10 > 4 ➔ Droite | Devient l'enfant **Droit** de 4. |
| 3 | **3** | 3 < 4 ➔ Gauche | Devient l'enfant **Gauche** de 4. |
| 4 | **5** | 5 > 4 (Droite) ➔ 5 < 10 (Gauche) | Devient l'enfant **Gauche** de 10. |
| 5 | **1** | 1 < 4 (Gauche) ➔ 1 < 3 (Gauche) | Devient l'enfant **Gauche** de 3. |

#### Résultat Visuel
L'arbre final ressemble à ceci :

```text
       4
     /   \
    3     10
   /     /
  1     5
```

---

### Ce que ça donne une fois rendu :

### 🌳 Exemple : Tri par Arbre Binaire de Recherche (BST)

**Tableau initial :** `[4, 10, 3, 5, 1]`

#### Étape 1 : Construction de l'arbre (Insertion)
| Tour | Nombre | Comparaisons (Le Chemin) | Action finale |
| :---: | :---: | :--- | :--- |
| 1 | **4** | *(L'arbre est vide)* | Devient la **Racine**. |
| 2 | **10** | 10 > 4 ➔ Droite | Devient l'enfant **Droit** de 4. |
| 3 | **3** | 3 < 4 ➔ Gauche | Devient l'enfant **Gauche** de 4. |
| 4 | **5** | 5 > 4 (Droite) ➔ 5 < 10 (Gauche) | Devient l'enfant **Gauche** de 10. |
| 5 | **1** | 1 < 4 (Gauche) ➔ 1 < 3 (Gauche) | Devient l'enfant **Gauche** de 3. |

#### Résultat Visuel
L'arbre final ressemble à ceci :

```text
       4
     /   \
    3     10
   /     /
  1     5
```
#### Étape 2 : Lecture (Parcours Infixe / In-Order)
On parcourt l'arbre en suivant la règle stricte : **Gauche ➔ Racine ➔ Droite**.

1.  On part de **4**, on va tout à gauche ➔ **3**, encore à gauche ➔ **1**. (Rien à gauche de 1).
    * 📝 On note : `1`
2.  On remonte au parent de 1.
    * 📝 On note : `3`
3.  On regarde à droite de 3 (Rien). On remonte à la racine.
    * 📝 On note : `4`
4.  On va à droite de 4 (vers le **10**). On regarde d'abord sa gauche (le **5**).
    * 📝 On note : `5`
5.  On remonte au **10**.
    * 📝 On note : `10`

✅ **Résultat trié :** `1, 3, 4, 5, 10`

</details>

---

<br>

</details>

<details>
<summary><strong>🟤 Complément : Tri stable et tri instable</strong></summary>

La notion de stabilité est fondamentale en algorithmique. Elle désigne la capacité d'un tri à préserver l'ordre relatif des éléments ayant la même valeur (doublons).

* **Tri Stable (Stable Sort)** : Si deux éléments sont égaux, celui qui apparaissait en premier dans la liste originale restera en premier dans la liste triée. C'est crucial lorsqu'on effectue des tris multicritères (ex: trier par nom, puis par âge sans perdre le tri alphabétique).

Exemples : Insertion Sort, Bubble Sort, Merge Sort.

* **Tri Instable (Unstable Sort)** : L'ordre relatif des éléments égaux n'est pas garanti et peut être modifié aléatoirement durant le processus. Ces algorithmes sont souvent plus rapides ou économes en mémoire, mais "perdent" l'information de l'ordre initial pour les doublons.

Exemples : Quick Sort, Selection Sort, Heap Sort.

</details>

## 5. Démarche et étapes de réalisation du projet

<details>
<summary><strong>🆗 Parsing</strong></summary>

* **fonction from_args_to_big_str :** récupérer les arguments entrés par l'utilisateur (sous la forme : "1 3 -12" ou  1 3 -12 ou encore un mixte des deux -par exemple : "1 3 " -12) et les placer dans une "big_str"
* **fonction put_args_in_array :** split de cette "big_str" dans un tableau de tableau (chaque ligne contient une string entrée par l'utilisateur, qui sera à transformer en entier)
* **fonction build_stack :**  vérifie la validité des arguments donnés 
	-	on vérifie d 'abord qu'il ne s'agit bien que de nombres
	-	on les transforme en entiers en utilisant atol plutôt que atoi (en cas d'overflow). Si atol renvoie bien un nombre, on vérifie l'oveflow.
	-	on vérifie l'absence de doublons.
	- si tout va bien, on construit la liste chaînée grâce à la fonction suivante.
* **NB :** Les fonctions relatives à la liste chaînée sont des variantes des fonctions de la libft, adaptées à la structure t_stack 
* **append_node :** fonction qui ajoute un nouveau noeud à la fin de la liste chaînée. Chaque nouveau noeud stocke la valeur d'un entier récupéré. Plus on avance dans les noeuds, plus on descend dans la pile.
* ex 1 2 3 donnera : 	1
						2
						3
* **NB :** Pour l'instant la structure est incomplète et ne contient pas les infos nécessaires au mode -benchmark
	typedef struct s_stack_node

```{
	/* data to complete */
	int					number;
	struct s_stack_node	*prev; // liste doublement chaînée pour faciliter ensuite les mouvements
	struct s_stack_node	*next;
}						t_stack;
```
* **index*** : Il s'agit d'associer un index à chaque valeur (!!!une fois la liste chaînée complétée) pour travailler ensuite sur les index, ce qui règle le problème des nombres négatifs et simplifie beaucoup le traitement. On a a priori besoin des index pour les algo moyens et complexes. Cet index doit être ajouté à la structure qui devient alors :

```{
	/* data to complete */
	int					number;
	int					index //le rang de l'entier dans la liste
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack;
```
* **Pour compléter ce champ index :** *
* **fonction index_stack**(dans le fichier sort_numbers) : On commence par mesurer la taille de la liste chaînée pour allouer la mémoire d'un tableau, dans lequel on copie les entiers. On travaille avec une copie du noeud pour éviter de perdre l'adresse de la liste. Dans ce tableau, on trie les entiers avec un bubble sort(* **fonction sort_numbers** *)(NB on se moque de la performance de ce pré-tri, c'est la performance des algos qui sera ensuite évaluée). 
Enfin, la fonction * **find_index** * cherche la correspondance entre l´entier stocké dans la liste chaînée et les valeurs du tableau trié (ex : tableau trié [2, 14, 22]) > je cherche dans quel noeud se trouve stockée la valeur "2" et j'associe à ce noeud l'index 0... etc...

</details>

<details>
<summary><strong>📝 Choix et implémentation des algorithmes</strong></summary>

### A. algorithme simple :
* **Stratégie choisie : tri par sélection**.

	Nous avons choisi d'implémenter un tri par sélection pour le ratio simplicité/efficacité de cet algorithme pour le tri des petites listes. Nous avons cherché à optimiser le tri en traitant à part les trois derniers nombres qui restent de la pile a (ou le tri se fait en un ou deux mouvements seulement). Un seconde optimisation consiste à faire tourner la pile dans un sens ou dans l'autre pour faire remonter l'index voulu en haut de la pile en fonction de la position de ce nombre dans la pile. En pseudo-code :

			on calcule la taille de la pile a
			on traite les cas où il y a moins de trois éléments dans la pile
			tant qu'il y a plus de trois éléments
				on détermine l index le plus petit
				s'il est dans la moitié haute de la pile 
					on le fait remonter avec des ra jusqu ce qu il soit tout en haut
				s il est dans la moitie basse de la pile
					on le fait remonter avec des rra jusqu ce qu il soit tout en haut
				on le pushe sur b avec pb
			on trie les 3 derniers éléments de a avec three_sort
			on vide dans a toute la pile b
			c'est trié !


### B. algorithme de complexité O(n√n) :
* **Statégie choisie : range-based sorting strategy**

Nous avons choisi cette variante du chunk-based sort pour son efficacité dans la catégorie des algorithmes de complexité O(n√n). Il s'agit de "pré-trier" les nombres en envoyant dans la pile b les nombres qui font partie de la plage [0- √size] (avec size qui correspond à la taille de la pile a). Au fur et à mesure qu'on envoie des nombres dans la pile b, on incrémente un compteur i et on adapte l'intervalle qui devient [0- √size + 1]. Voici la logique de l'implémemtation en pseudo-code :

			
			
			on compte le nombre d elements de la stack a = size
			on determine le range (racine de size)*
			on met un incrementateur count a 0
			ETAPE 1 : ON PRE-TRIE 
			tant que a n est pas vide
				si index est compris dans l'intervalle [0 ; range + i]
					on pushe dans b
					si index < i (cad s'il s'agit d'un petit index)
						rb (on l'envoie au fond de la pile b)
						on incrémente le compteur
				sinon on fait tourner la pile a (avec ra)	
			NB a la fin de cette boucle, les nombres sont pre tries, grands au dessus, petits en dessous, moyens au milieu
			ETAPE 2 : ON TRIE LA PILE B "PRE-TRIEE"
			tant que b n'est pas vide
			on regarde si l'un des deux plus grands index se trouve sur le dessus de la pile (c'est une optimisation!)
			si oui 
				on pushe dans a
				s il y a plus d´un element dans a
					on vérifie que les deux nombres en haut de la pile a sont triés 
					si ce n'est pas le cas, on les swap
			si non
				on regarde à quelle position se trouve index_max
				s'il est encore dans la moitié haute de la pile
					on fait tourner avec rb
				s´il est dans le bas de la pile
					on le fait remonter avec des rrb

### C. algorithme de complexité O(n log n) :
* **Statégie choisie : Radix Sort**

Nous avons sélectionné le Radix Sort (en base 2) pour son efficacité sur les très grands jeux de données (N ≥ 5000). Il s'agit d'un algorithme de complexité O(n log n). La stratégie ne repose pas sur la comparaison des valeurs entre elles, mais sur le traitement de leur représentation binaire, du bit de poids faible vers le bit de poids fort. Pour simplifier le traitement (et gérer les nombres négatifs), nous associons d'abord chaque nombre à son rang final (de 0 à size-1). Ensuite, pour chaque position de bit, nous filtrons la pile a : les nombres ayant un bit à 0 sont envoyés dans la pile b, tandis que ceux ayant un bit à 1 restent dans la pile a (via rotation). Après chaque passe, on rassemble tout en reversant b sur a, ce qui ordonne progressivement la liste.

Voici la logique de l'implémentation en pseudo-code :


		Initialisation & Pré-traitement :
		On parcourt la pile A pour associer à chaque nombre son **index final** (de 0 à size-1).
		(Cela permet de ne travailler qu'avec des nombres positifs et simplifie le tri binaire).
		On détermine le nombre de bits nécessaires (`max_bits`) pour écrire le plus grand index.
		On initialise un compteur de position de bit `i` à 0.

		BOUCLE PRINCIPALE : TRAITEMENT BIT PAR BIT
		TANT QUE `i` est inférieur à `max_bits` :

    		Phase 1 : Distribution (Tri selon le bit i)
    		On répète l'opération `size` fois (pour chaque élément de A) :
        	On regarde l'index du nombre au sommet de la pile A (head).
        		SI le bit à la position `i` est égal à 0 :
            		On le pousse dans la pile B (`pb`).
        		SINON (si le bit est égal à 1) :
           			 On le laisse dans A et on fait tourner la pile (`ra`).
    
    		Phase 2 : Rassemblement (Reconstitution)
    		TANT QUE la pile B n'est pas vide :
        		On repousse tout le contenu de B sur A (`pa`).
        		(Comme B est vidé sur A, les nombres ayant un '0' se retrouvent au-dessus, et l'ordre relatif est conservé).

			Phase 3 : Passage au bit suivant
    		On incrémente `i` (on passe au bit de poids supérieur).

		À la fin de la boucle (après le traitement du dernier bit), la pile A est entièrement triée.


</details>

<details>
<summary><strong>📝 Algorithme adaptatif</strong></summary>


Pour définir la stratégie à adopter, nous nous sommes appuyés sur des tests prenant en compte le désordre et la longueur de la liste à trier. Les données reportées sont représentatives d'un score "moyen"à "mauvais" (sauf pour le radix sort où le nombre d'opérations est fixe quel que soit le désordre). Les meilleurs résultats sont indiqués en **gras**. :

</details>

<details>
<summary><strong>📊 Analyse</strong></summary>

### 📊 Analyse des Petites Listes (N = 5, 10, 20)

Ce tableau présente l'évolution de la performance sur les petites tailles de listes. Il justifie pourquoi l'algorithme adaptatif moyen ou complexe n'est activé qu'au-delà de 20 éléments.

* **Sel** : Selection Sort (Tri simple optimisé).
* **Ran** : Range-Based Sort (Tri par paquets $O(N\sqrt{N})$).
* **Rad** : Radix Sort (Binaire $O(N \log N)$).

| Désordre | N=5 (Sel) | N=5 (Ran) | N=5 (Rad) | N=10 (Sel) | N=10 (Ran) | N=10 (Rad) | N=20 (Sel) | N=20 (Ran) | N=20 (Rad) |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0.1** | **6** | 13 | 25 | **16** | 24 | 50 | **32** | 55 | 212 |
| **0.2** | **7** | 15 | 25 | **20** | 28 | 50 | **38** | 60 | 212 |
| **0.3** | **8** | 15 | 25 | **21** | 27 | 50 | **55** | 65 | 212 |
| **0.4** | **7** | 13 | 25 | **21** | 36 | 50 | **75** | 70 | 212 |
| **0.5** | **8** | 12 | 25 | **24** | 31 | 50 | 92 | **75** | 212 |
| **0.6** | **9** | 17 | 25 | **19** | 25 | 50 | 80 | **80** | 212 |
| **0.7** | **8** | 15 | 25 | **23** | 29 | 50 | **65** | 85 | 212 |
| **0.8** | **9** | 16 | 25 | **24** | 38 | 50 | **50** | 90 | 212 |
| **0.9** | **8** | 17 | 25 | **23** | 42 | 50 | **40** | 95 | 212 |
| **1.0** | **8** | 18 | 25 | **23** | 40 | 50 | **38** | 98 | 212 |



#### 💡 Analyse de la progression :

1.  **Hégémonie du Selection Sort ($N \le 10$)** :
    * Jusqu'à 10 éléments, le **Selection Sort** domine totalement. Il est 2 à 3 fois plus rapide que le Radix ou le Range Sort.
    * *Conclusion :* Un algorithme simple est impératif pour ces tailles afin d'éviter le gaspillage de mouvements. Le **selection Sort** reste le plus efficace pour les listes de moins de 20 nombres. Le **range_based_sort** devient ensemble plus efficace lorsque le désordre est autour de 0.5.
    * Le **Radix** est ici hors-jeu (212 coups) : le coût fixe des passes binaires (5 bits nécessaires) est trop lourd pour une si petite liste.

### 📊 Analyse des Listes Moyennes (N = 50 à 500)

* **Sel** : Selection Sort (Tri simple optimisé).
* **Ran** : Range-Based Sort (Tri par paquets $O(N\sqrt{N})$).
* **Rad** : Radix Sort (Binaire $O(N \log N)$).

| Désordre | N=50 (Sel) | N=50 (Ran) | N=50 (Rad) | N=100 (Sel) | N=100 (Ran) | N=100 (Rad) | N=500 (Sel) | N=500 (Ran) | N=500 (Rad) |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0.1** | **100** | 111 | 467 | **180** | 350 | 1050 | 3900 | **1239** | 6784 |
| **0.2** | **127** | 138 | 467 | **250** | 380 | 1050 | 5688 | **1600** | 6784 |
| **0.3** | **125** | 152 | 467 | **350** | 450 | 1050 | 8546 | **2122** | 6784 |
| **0.4** | 310 | **200** | 467 | 600 | **520** | 1050 | 9183 | **2343** | 6784 |
| **0.5** | 514 | **241** | 467 | 900 | **600** | 1050 | 11123 | **2779** | 6784 |
| **0.6** | 388 | **253** | 467 | 800 | **680** | 1050 | 14037 | **3019** | 6784 |
| **0.7** | **235** | 293 | 467 | **500** | 750 | 1050 | 16226 | **3443** | 6784 |
| **0.8** | **178** | 292 | 467 | **400** | 820 | 1050 | 22416 | **4053** | 6784 |
| **0.9** | **143** | 332 | 467 | **300** | 950 | 1050 | 25798 | **4482** | 6784 |
| **1.0** | **143** | 331 | 467 | **320** | 1100 | 1050 | 25510 | **6355** | 6784 |

#### 💡 Analyse comparative :

1.  **N=50 & N=100 (Sel vs Ran) :**
    * Le **Selection Sort (Sel)** reste très pertinent pour les cas extrêmes (très trié ou inversé), car il profite des optimisations apportées.
    * Le **Range Sort (Ran)** prend l'avantage uniquement dans la zone de "désordre intermédiaire" (0.4 à 0.6).
    * Le **Radix** est trop lourd (coût fixe constant trop élevé).

2.  **N=500 (choix du Range Sort) :**
    * Le **Range Sort (Ran)** devient l'algorithme dominant absolu. Il bat le Radix même dans le pire cas (6355 contre 6794 coups).
    * Le **Selection Sort** s'effondre totalement (dépassant les 25 000 coups) et n 'est plus pertinent à partir de ce seuil.

	### 📊 Analyse grandes Listes (N = 1000, 3000)

Pour ces tailles, les algorithmes de type $O(N^2)$ (Selection Sort) sont exclus car trop lents.
Ce tableau compare uniquement le **Range-Based Sort** (Tri par paquets) et le **Radix Sort** (Base 2).

* **Ran** : Range-Based Sort (Optimisé avec heuristiques).
* **Rad** : Radix Sort (Performance stable peu importe le désordre).

| Désordre | N=1000 (Ran) | N=1000 (Rad) | N=3000 (Ran) | N=3000 (Rad) |
| :---: | :---: | :---: | :---: | :---: |
| **0.1** | **2 548** | 15 060 | **11 445** | 55 172 |
| **0.2** | **4 596** | 15 060 | **21 757** | 55 172 |
| **0.3** | **5 594** | 15 060 | **30 023** | 55 172 |
| **0.4** | **6 671** | 15 060 | **38 339** | 55 172 |
| **0.5** | **8 239** | 15 060 | **45 636** | 55 172 |
| **0.6** | **9 276** | 15 060 | 55 712 | **55 172** |
| **0.7** | **10 420** | 15 060 | 58 012 | **55 172** |
| **0.8** | **11 641** | 15 060 | 62 518 | **55 172** |
| **0.9** | **11 757** | 15 060 | 63 386 | **55 172** |
| **1.0** | 19 521 | **15 060** | 93 646 | **55 172** |

### 📊 Analyse des très Grandes Listes (N = 5000, 10000)

On observe que pour des volumes très importants, la stabilité du **Radix Sort** finit par surpasser le **Range Sort** dès que le désordre est significatif. Pour une liste de 10000 nombres, le **radix** l'emporte à tous les coups.

| Désordre | N=5000 (Ran) | N=5000 (Rad) | N=10000 (Ran) | N=10000 (Rad) |
| :---: | :---: | :---: | :---: | :---: |
| **0.2** | **82 462** | 100 190 | 224 167 | **215 392** |
| **0.5** | 111 601 | **100 190** | 385 956 | **215 392** |
| **0.8** | 110 874 | **100 190** | 502 721 | **215 392** |

</details>

<details>
<summary><strong>📉 Calcul de la complexité des algorithmes</strong></summary>


Cette section a pour but de vérifier si nos algorithmes correspondent bien à leur complexité théorique annoncée, en utilisant la formule du facteur de croissance ($\alpha$).

---

#### 🐢 Algorithme simple (select_sort)

On prend comme repères les valeurs pour **N = 100** et **N = 500** (pire cas).

* Calcul du grossissement de la liste : $Ratio_N = 500/100 = \mathbf{5}$
* Calcul du grossissement du nombre d'opérations : $Ratio_{Ops} = 25\,798 / 900 \approx \mathbf{28.6}$

On est donc proche de $O(N^2)$ car $5^2 = 25$. On applique la formule logarithmique pour trouver la puissance exacte :

$$
\alpha = \frac{\ln(28.6)}{\ln(5)} \approx \frac{3.35}{1.61} \approx \mathbf{2.08}
$$

> **Conclusion :** L'exposant $\alpha$ étant très proche de **2**		(NB : résultat théorique attendu : ln(25) / ln(5) = 2)), cela confirme que la complexité de l'algorithme est **$O(N^2)$**. C'est pour cette raison que cet algorithme n'est plus utilisé au-delà de 100 nombres (l'explosion du nombre de coups devient ingérable).

---

#### 🐇 Algorithme moyen (range-based sorting strategy)

On compare l'évolution du nombre d'opérations sur des listes de taille moyenne à grande avec un désordre standard (0.5).

* **Données mesurées :** $N = 1000$ (8 239 coups) et $N = 3000$ (45 636 coups).
* Calcul du grossissement de la liste : $Ratio_N = 3000 / 1000 = \mathbf{3}$
* Calcul du grossissement des opérations :

$$
Ratio_{Ops} = \frac{45 636}{8 239} \approx \mathbf{5.54}
$$

Théoriquement, la complexité $N\sqrt{N}$ donnerait ici $3\sqrt{3} \approx 5.19$. On est très proche. On confirme en appliquant la formule logarithmique :

$$
\alpha = \frac{\ln(5.54)}{\ln(3)} \approx \frac{1.71}{1.10} \approx \mathbf{1.56}
$$

> **Conclusion :** L'exposant $\alpha \approx 1.5$ indique une complexité proche de **$O(N \sqrt{N})$** (NB : résultat théorique : ln(5.19) / ln(3) = 1.49)  C'est nettement plus performant que le Selection Sort ($\alpha \approx 2$), mais cela explique pourquoi le **Range Sort** finit par être dépassé par le **Radix Sort** sur les très grandes listes.

---

#### 🚀 Algorithme complexe (radix_sort)

Pour le radix_sort, nous observons une grande stabilité sur les très grandes listes. Nous allons démontrer pourquoi la complexité théorique $O(N \times k)$ est strictement équivalente à $O(N \log N)$.

* **Données mesurées :** $N = 5000$ (100 190 coups) et $N = 10000$ (215 392 coups).
* **Ratio observé :**
    $$
    Ratio_{Ops} = \frac{215 392}{100 190} \approx \mathbf{2.15}
    $$

**1. Calcul via les bits ($N \times k$) :**
* Pour $N = 5000$ : Il faut **13 bits** ($2^{13} = 8192$).
* Pour $N = 10000$ : Il faut **14 bits** ($2^{14} = 16384$).

$$
Ratio_{Théorique} = \frac{10000 \times 14}{5000 \times 13} = 2 \times \frac{14}{13} \approx \mathbf{2.15}
$$

**2. Calcul via les logarithmes ($N \log N$) :**
En base 2, le nombre de bits $k$ est défini par le logarithme : $k \approx \log_2(N)$.

$$
Ratio_{Log} = \frac{10000 \times \log_2(10000)}{5000 \times \log_2(5000)} \approx 2 \times \frac{13.29}{12.29} \approx \mathbf{2.16}
$$

> **Conclusion :** Les deux calculs mènent au même résultat (~2.15), ce qui confirme que l'algorithme suit bien une complexité **$O(N \log N)$**.

---

### 📊 Récapitulatif 

| Algorithme | Ratio N testé | Ratio Ops Mesuré | Exposant calculé ($\alpha$) | Complexité Validée |
| :--- | :---: | :---: | :---: | :--- |
| **Selection** | x5 | x28.6 | **2.08** | $O(N^2)$ |
| **Range** | x3 | x5.54 | **1.56** | $O(N\sqrt{N})$ |
| **Radix** | x2 | x2.15 | **1.10** | $O(N \log N)$ |
</details>

</details>

## 6. Contributions

<details>
<summary><strong>👥 Contributions</strong></summary>

<br>

| Fonctionnalité | Auteurs / Responsables |
| :--- | :--- |
| **Parsing & Validation** | `stmaire` |
| **Gestion des Flags** | `marberge` |
| **Benchmark & Tests** | `marberge` |
| **Opérations (Instructions)** | `marberge` & `stmaire` |
| **Algo : Simple Sort** | `marberge` & `stmaire` |
| **Algo : Medium Sort** | `stmaire` |
| **Algo : Complex Sort** | `marberge` |
| **Sélecteur Adaptatif** | `stmaire` |
| **Documentation (README)** | `stmaire` |

</details>
