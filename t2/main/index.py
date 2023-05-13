import matplotlib.pyplot as plt

insertionSortFile = open("files/insertionSort.txt")
bubbleSortFile = open("files/bubbleSort.txt")
quickSortFile = open("files/quickSort.txt")
mergeSortFile = open("files/mergeSort.txt")
heapSortFile = open("files/heapSort.txt")
linearSearchFile = open("files/linearSearch.txt")
binarySearchFile = open("files/binarySearch.txt")

# InsertionSort
# BubbleSort
# QuickSort
# MergeSort
# HeapSort
# LinearSearch
# BinarySearch

def extractDataFromFile(file):
  # Extract every single line of the file
  lines = [file.readline() for _ in range(0, 15)]

  # Get every single value from the file
  values = [int(line.split()[1]) for line in lines]

  return values

def generate_scatter(x, y, label, path):
  plt.clf()
  plt.scatter(x, y, 16, "red", label=label)
  plt.legend(loc='upper right', scatterpoints=1, markerscale=1)
  plt.savefig(path)

x = [10, 30, 50, 70, 90, 100, 300, 500, 700, 900, 1000, 3000, 5000, 7000, 9000]

# InsertionSort
# BubbleSort
# QuickSort
# MergeSort
# HeapSort
# LinearSearch
# BinarySearch

insertionSortValues = extractDataFromFile(insertionSortFile)
bubbleSortValues = extractDataFromFile(bubbleSortFile)
quickSortValues = extractDataFromFile(quickSortFile)
mergeSortValues = extractDataFromFile(mergeSortFile)
heapSortValues = extractDataFromFile(heapSortFile)
linearSearchValues = extractDataFromFile(linearSearchFile)
binarySearchValues = extractDataFromFile(binarySearchFile)

generate_scatter(x, insertionSortValues, "Insertion Sort", "files/insertionSort.png")
generate_scatter(x, bubbleSortValues, "Bubble Sort", "files/bubbleSort.png")
generate_scatter(x, quickSortValues, "Quick Sort", "files/quickSort.png")
generate_scatter(x, mergeSortValues, "Merge Sort", "files/mergeSort.png")
generate_scatter(x, heapSortValues, "Heap Sort", "files/heapSort.png")
generate_scatter(x, linearSearchValues, "Linear Search", "files/linearSearch.png")
generate_scatter(x, binarySearchValues, "Binary Search", "files/binarySearch.png")



