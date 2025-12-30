This project has been created as part of the 42 curriculum by               


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

### 🚀 Le Défi de la Complexité

Pour atteindre le grade "Excellent", ce programme implémente une **stratégie adaptative**. Avant de trier, il calcule le **taux de désordre** de la liste pour sélectionner l'algorithme le plus performant :

* **Faible désordre / Petite liste (< 0.2)** :
    * *Stratégie :* Réparation locale ou tri simple ($O(n)$ ou $O(n^2)$).
* **Désordre moyen (0.2 - 0.5)** :
    * *Stratégie :* Algorithme par "Chunks" / Tronçons ($O(n\sqrt{n})$).
* **Grandes listes / Chaos total (≥ 0.5)** :
    * *Stratégie :* Algorithmes divisés type Radix ou Quick Sort ($O(n \log n)$).

### ⚡ Modes de Fonctionnement

Afin de faciliter le contrôle des performances, le programme intègre plusieurs modes d'exécution activables via des drapeaux (flags) :

* **Mode Automatique (Par défaut)** : Le programme est autonome. Il scanne la pile et choisit la meilleure stratégie pour minimiser les coups.
* **Modes Forcés (`--simple`, `--medium`, `--complex`)** : Ces options permettent de désactiver l'intelligence artificielle du programme pour forcer l'utilisation d'un algorithme spécifique, quelle que soit la taille de la liste. C'est idéal pour vérifier la robustesse de chaque méthode individuellement.
* **Mode Benchmark (`--bench`)** : Transforme le programme en outil d'analyse scientifique. En plus de trier, il calcule et affiche des statistiques précises sur la **sortie d'erreur** (taux de désordre, stratégie utilisée, compteurs d'opérations détaillés), permettant une validation rigoureuse sans perturber le checker.







## 🧠 Stratégies Algorithmiques & Complexité

Pour résoudre efficacement le problème de tri quelle que soit la taille de l'entrée, ce projet implémente trois approches algorithmiques distinctes, allant de la méthode naïve à la plus optimisée, conformément aux exigences du sujet.

### 1. L'Algorithme Simple O(n²)
* **Cible :** Petites piles (3 à ~10 valeurs).
* **Stratégie :** **Tri par Sélection** (Approche gloutonne / *Greedy*).
* **Fonctionnement :** L'algorithme parcourt la totalité de la pile `a` pour trouver le plus petit nombre (minimum), le pousse vers la pile `b`, et répète le processus jusqu'à ce que `a` soit vide.
* **Pourquoi O(n²) ?** Pour chaque nombre individuel que l'on veut trier (n), on doit parcourir la quasi-totalité de la pile (n) pour le trouver.
    * *Coût :* Élevé (~ n × n opérations), mais suffisamment efficace pour de très petites listes où la surcharge est minime.

### 2. L'Algorithme Moyen O(n√n)
* **Cible :** Piles moyennes (ex : 100 valeurs).
* **Stratégie :** **Tri par Tronçons** ou **Chunks** (Variante du Tri par Paquets / *Bucket Sort*).
* **Fonctionnement :**
    1.  La pile est virtuellement divisée en plages de valeurs appelées "chunks". Le nombre de chunks est déterminé par la racine carrée du nombre total d'éléments (√n).
    2.  Au lieu de chercher un nombre précis (comme le minimum exact), l'algorithme cherche **n'importe quel** nombre appartenant au chunk actuel.
    3.  Une fois poussés sur la pile `b`, les éléments sont grossièrement triés par groupes. Ils sont ensuite repoussés vers `a` avec un tri précis.
* **Pourquoi O(n√n) ?** Chercher "n'importe quel élément d'un chunk" est statistiquement bien plus rapide que de chercher un élément spécifique. On effectue `n` poussées, mais avec un coût de recherche réduit à `√n` en moyenne.

### 3. L'Algorithme Complexe O(n log n)
* **Cible :** Grandes piles (500+ valeurs).
* **Stratégie :** **Radix Sort** (Tri par base) ou **Quick Sort** (Tri rapide / Turk Algo).
* **Fonctionnement :** Utilise une approche **"Diviser pour régner"** (*Divide and Conquer*). L'algorithme divise récursivement la pile en partitions jusqu'à ce que les données soient assez fines pour être triées instantanément.
* **Pourquoi O(n log n) ?**
    * En informatique, **log n** (logarithme en base 2) est la réponse à la question : **"Combien de fois puis-je couper ma liste en deux avant qu'il ne reste plus qu'un seul élément ?"**
    * Pour 500 nombres, la réponse est seulement 9 (log₂ 500 ≈ 9).
    * Au lieu de faire 500 tours de boucle (comme le tri simple), cet algorithme ne nécessite qu'environ 9 niveaux de division pour isoler et trier chaque nombre. C'est ce qui le rend exponentiellement plus rapide.

---

### ⚡ Résumé des Performances

| Algorithme | Complexité | Taille Entrée | Opérations Est. (500 nbs) | Statut |
| :--- | :--- | :--- | :--- | :--- |
| **Simple** | Quadratique O(n²) | < 10 | ~250 000 (Trop lent) | ❌ |
| **Moyen** | Racine O(n√n) | ~100 | ~11 000 | ✅ Réussite (Min) |
| **Complexe** | Linéarithmique O(n log n) | 500+ | < 5 500 | 🏆 Excellent |
