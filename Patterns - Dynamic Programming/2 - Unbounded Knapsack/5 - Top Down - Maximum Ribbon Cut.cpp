public int countRibbonPieces(int[] ribbonLengths, int total) {
  int maxPieces = this.countRibbonPiecesRecursive(ribbonLengths, total, 0);
  return maxPieces == Integer.MIN_VALUE ? -1 : maxPieces;
}

private int countRibbonPiecesRecursive(int[] ribbonLengths, int total, int currentIndex) {
  // base check
  if (total == 0)
    return 0;

  if(ribbonLengths.length == 0 || currentIndex >= ribbonLengths.length)
    return Integer.MIN_VALUE;

  // recursive call after selecting the ribbon length at the currentIndex
  // if the ribbon length at the currentIndex exceeds the total, we shouldn't process this
  int c1 = Integer.MIN_VALUE;
  if( ribbonLengths[currentIndex] <= total ) {
    int result = countRibbonPiecesRecursive(
                  ribbonLengths, total - ribbonLengths[currentIndex], currentIndex);
    if(result != Integer.MIN_VALUE){
      c1 = result + 1;
    }
  }

  // recursive call after excluding the ribbon length at the currentIndex
  int c2 = countRibbonPiecesRecursive(ribbonLengths, total, currentIndex + 1);
  return Math.max(c1, c2);
}
