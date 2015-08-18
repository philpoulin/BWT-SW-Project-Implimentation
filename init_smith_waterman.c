	void init_smith_waterman(struct node* root, SA_BWT indexes){
		struct S_E range, rangeA, rangeC, rangeG, rangeT;
		range.s = 1;
		range.e = indexes.length;		
		int i; 
		for (i = 0; i < R_SIZE; i++){
			results[i].score = 0;
		}
		rangeA = backwards_search(indexes, 'A', range);
		if (rangeA.s <= rangeA.e) smith_waterman_recursion(root, indexes, 'A', rangeA);

		rangeC = backwards_search(indexes, 'C', range);
		if (rangeC.s <= rangeC.e) smith_waterman_recursion(root, indexes, 'C', rangeC);

		rangeG = backwards_search(indexes, 'G', range);
		if (rangeG.s <= rangeG.e) smith_waterman_recursion(root, indexes, 'G', rangeG);

		rangeT = backwards_search(indexes, 'T', range);
		if (rangeT.s <= rangeT.e) smith_waterman_recursion(root, indexes, 'T', rangeT);
	}
