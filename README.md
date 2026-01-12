*This project has been created as part of the 42 curriculum by marberge et stmaire.*             


## 📝 Description

**Push_swap** est un projet d'algorithmique avancé qui consiste à trier des données sur une pile (stack), avec un jeu d'instructions limité et en un nombre de coups strictement optimisé.

Le défi principal n'est pas seulement de trier, mais de le faire avec une **efficacité mathématique**. Le programme ne se contente pas d'appliquer une méthode unique : il est conçu pour être **intelligent et adaptatif**, analysant les données avant d'agir.

### 🎮 Les Règles du Jeu

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

Pour atteindre le grade "Excellent", ce programme implémente une **stratégie adaptative**. Avant de trier, il calcule le **taux de désordre** de la liste pour sélectionner l'algorithme le plus performant :

* **Faible désordre / Petite liste (< 0.2)** :
    * *Stratégie :* Réparation locale ou tri simple ($O(n)$ ou $O(n^2)$).
* **Désordre moyen (0.2 - 0.5)** :
    * *Stratégie :* Algorithme par "Chunks" / Tronçons ($O(n\sqrt{n})$).
* **Grandes listes / Chaos total (≥ 0.5)** :
    * *Stratégie :* Algorithmes divisés type Radix ou Quick Sort ($O(n \log n)$).

### ⚡ Modes de Fonctionnement

Afin de faciliter le contrôle des performances, le programme intègre plusieurs modes d'exécution activables via des drapeaux (flags):

* **Mode Automatique (Par défaut)** : Le programme est autonome. Il scanne la pile et choisit la meilleure stratégie pour minimiser les coups.
* **Modes Forcés (`--simple`, `--medium`, `--complex`)** : Ces options permettent de désactiver l'intelligence artificielle du programme pour forcer l'utilisation d'un algorithme spécifique, quelle que soit la taille de la liste. C'est idéal pour vérifier la robustesse de chaque méthode individuellement.
* **Mode Benchmark (`--bench`)** : Transforme le programme en outil d'analyse scientifique. En plus de trier, il calcule et affiche des statistiques précises sur la **sortie d'erreur** (taux de désordre, stratégie utilisée, compteurs d'opérations détaillés), permettant une validation rigoureuse sans perturber le checker.

## 💻 Instructions

### 🔧 Compilation

Le projet est écrit en C et utilise un `Makefile` pour la compilation. Assurez-vous d'avoir `gcc` et `make` installés sur votre machine.

1.  **Cloner le dépôt :**
    ```bash
    git clone [https://github.com/votre-username/push_swap.git](https://github.com/votre-username/push_swap.git)
    cd push_swap
    ```

2.  **Compiler le programme :**
    Cette commande génère l'exécutable `push_swap`.
    ```bash
    make
    ```

---

### 🚀 Exécution

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

### 🚩 Options & Drapeaux

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
### ✅ Vérification (Checker)

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
### 🧹 Nettoyage

* **`make clean`** : Supprime les fichiers objets (`.o`).
* **`make fclean`** : Supprime les fichiers objets et l'exécutable `push_swap`.
* **`make re`** : Recompile tout depuis zéro.

## 📚 Ressources & Références

Voici une sélectionde ressources techniques pour comprendre les algorithmes implémentés et les outils utilisés pour valider le projet.

### 🧠 Algorithmes & Stratégies

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



### 🛠️ Outils de Test & Visualisation

* **[push_swap_visualizer (o-reo)](https://github.com/o-reo/push_swap_visualizer)** : Un outil graphique indispensable pour **voir** les piles bouger en temps réel. Il permet de comprendre visuellement la logique de tri et de débugger les boucles infinies.
* **[push_swap_tester (SimonCROS)](https://github.com/SimonCROS/push_swap_tester)** : Un script de benchmark complet pour lancer des milliers de tests aléatoires, vérifier la gestion des erreurs et calculer la moyenne de coups. Essentiel pour calibrer le mode adaptatif.

### 🎓 Théorie

* **[CS50 - Asymptotic Notation](https://www.youtube.com/watch?v=iOq5kSKjRGI)** : (Vidéo) Explication sur la complexité algorithmique et le "Big O", issue du cours d'Harvard.

## 🧠 Stratégies Algorithmiques & Complexité

Pour résoudre efficacement le problème de tri quelle que soit la taille de l'entrée, ce projet implémente trois approches algorithmiques distinctes, allant de la méthode naïve à la plus optimisée, conformément aux exigences du sujet.

### 1. L'Algorithme Simple O(n²)
* **Cible :** Petites piles (3 à ~10 valeurs).

* **Strategies possibles (quelques exemples) :**

-- **Bubble sort** : On parcourt la pile. Si le nombre du haut est plus grand que le suivant, on les échange (sa). Sinon, on passe au suivant (ra). Après un premier parcours complet du tableau, le plus grand élément est forcément en fin de tableau, à sa position définitive. On recommence à parcourir le tableau tant que tout n'est pas trié. Cet algorithme consomme énormément de mouvements (sa, ra en boucle). 

-- **Tri par insertion (Insertion Sort) :** On prend le nombre en haut de `a` (pb), et on l'insère à la bonne place dans la pile `b` (qui est toujours triée). À la fin, on remet tout dans `a`. Solution complexe à coder car, vu qu'elle insère au bon endroit dans la pile, cela demande de calculer les coûts de rotation.

-- **Tri par Sélection :** L'algorithme parcourt la totalité de la pile `a` pour trouver le plus petit nombre (minimum), le pousse vers la pile `b`, et répète le processus jusqu'à ce que `a` soit vide. Très facile à coder. Coût élevé (~ n × n opérations), mais suffisamment efficace pour de très petites listes où la surcharge est minime.

-- **L'Extraction Min/Max (Extraction Method) :**
C'est une version plus "flexible" du tri par sélection, qui peut être utilisée pour optimiser les coups. Il s'agit de vider la pile `a`A le plus vite possible en enlevant les "extrêmes". La méthode : Regarder la pile `a`. Se demander : "Qui est le plus près du haut ? Le Minimum ou le Maximum ?" Si le Min est plus près : on le monte et pb (et on le laisse en haut de `b`). Si le Max est plus près : on le monte et pb (et on le met en bas de 'b' avec rb). La pile `b` est donc triée au fur et à mesure, mais on a économisé des rotations en choisissant le chemin le plus court (vers le Min ou vers le Max). NB : au delà de 3 nombres, cela ne fonctionne plus sans adaptations car `b` n'est plus trié...

* **Statégie choisie :**
*A COMPLETER*

### 2. L'Algorithme Moyen O(n√n)
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

* **Statégie choisie :**
*A COMPLETER*

### 3. L'Algorithme Complexe O(n log n)
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
	<summary>tableau comparatif LSD/MSD</summary>

| Critère | LSD (Least Significant Digit) | MSD (Most Significant Digit) |
| :--- | :--- | :--- |
| **Logique** | De Droite à Gauche (Bit 0 $\rightarrow$ Bit Max) | De Gauche à Droite (Bit Max $\rightarrow$ Bit 0) |
| **Structure** | **Itératif** (Une simple boucle `for`) | **Récursif** (Nécessite des appels de fonctions imbriqués) |
| **Gestion des Piles** | On traite **toute** la pile A à chaque tour (A $\leftrightarrow$ B). | On doit gérer des **sous-portions** de piles isolées. |
| **Complexité Code** | ✅ **Très facile** (Idéal pour Push_swap). | ⚠️ **Difficile** (Gestion d'index et de récursivité complexe). |
| **Efficacité** | **Constante** (Le nombre de coups est prévisible). | **Variable** (Potentiellement plus rapide, mais dur à optimiser).

</details>
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

<details><summary>🌳 Exemple : Tri par Arbre Binaire de Recherche (BST)</summary>

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
<br>

* **Statégie choisie :**
*A COMPLETER*

### 4. Complément : Algorithme adaptatif
*A COMPLETER*


### 5. Complément : Tri stable et tri instable

La notion de stabilité est fondamentale en algorithmique. Elle désigne la capacité d'un tri à préserver l'ordre relatif des éléments ayant la même valeur (doublons).

* **Tri Stable (Stable Sort)** : Si deux éléments sont égaux, celui qui apparaissait en premier dans la liste originale restera en premier dans la liste triée. C'est crucial lorsqu'on effectue des tris multicritères (ex: trier par nom, puis par âge sans perdre le tri alphabétique).

Exemples : Insertion Sort, Bubble Sort, Merge Sort.

* **Tri Instable (Unstable Sort)** : L'ordre relatif des éléments égaux n'est pas garanti et peut être modifié aléatoirement durant le processus. Ces algorithmes sont souvent plus rapides ou économes en mémoire, mais "perdent" l'information de l'ordre initial pour les doublons.

Exemples : Quick Sort, Selection Sort, Heap Sort.

## Contributions

* préciser le rôle de chacun dans le projet

*A COMPLETER*

## Démarche et étapes de réalisation du projet

### 1. Parsing

* **fonction from_args_to_big_str :** récupérer les arguments entrés par l'utilisateur (sous la forme : "1 3 -12" ou  1 3 -12 ou encore un mixte des deux -par exemple : "1 3 " -12) et les placer dans une "big_str"
* **fonction put_args_in_array :** split de cette "big_str" dans un tableau de tableau (chaque ligne contient une string entrée par l'utilisateur, qui sera à transformer en entier)
* **fonction build_stack :**  vérifie la validité des arguments donnés 
	-	on vérifie d 'abord qu'il ne s'agit bien que de nombres
	-	on les transforme en entiers en utilisant atol plutôt que atoi (en cas d'overflow). Si atol renvoie bien un nombre, on vérifie l'oveflow.
	-	on vérifie l'absence de doublons.
	- si tout va bien, on construit la liste chaînée grâce à la fonction suivante.
* **NB :** Les fonctions relatives à la liste chaînée sont des variantes des fonctions de la libft, adaptées à la structure t_stack_node 
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
}						t_stack_node;
```
* **index*** : Il s'agit d'associer un index à chaque valeur (!!!une fois la liste chaînée complétée) pour travailler ensuite sur les index, ce qui règle le problème des nombres négatifs et simplifie beaucoup le traitement. On a a priori bsoin des index pour les algo moyens et complexes. Cet index doit être ajouté à la structure qui devient alors :

```{
	/* data to complete */
	int					number;
	int					index //le rang de l'entier dans la liste
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;
```
* **Pour compléter ce champ index :** *
* **fonction index_stack**(dans le fichier sort_numbers) : On commence par mesurer la taille de la liste chaînée pour allouer la mémoire d'un tableau, dans lequel on copie les entiers. On travaille avec une copie du noeud pour eviter de perdre l adresse de la liste. Dans ce tableau, on trie les entiers avec un bubble sort(* **fonction sort_numbers** *)(NB on se moque de la performance de ce pré-tri, c'est la performance des algos qui sera ensuite évaluée). 
Enfin, la fonction * **find_index** * cherche la correspondance entre l´entier stocké dans la liste chaînée et les valeurs du tableau trié (ex : tableau trié [2, 14, 22]) > je cherche dans quel noeud se trouve stockée la valeur "2" et j'associe à ce noeud l'index 0... etc...

