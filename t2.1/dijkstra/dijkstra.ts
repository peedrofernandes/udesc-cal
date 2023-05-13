export default class MinHeapPriorityQueue<T> {
  private heap: T[]
  private getPriority: (t: T) => number

  constructor(enumerator: (t: T) => number, values?: T[]) {
    this.heap = []
    this.getPriority = (t?: T): number => {
      if (t) return enumerator(t)
      else return -1
    }
    
    if (values)
      values.forEach(value => this.enqueue(value))
  }

  private min(t1: T, t2: T): T | null {
    const p1 = this.getPriority(t1)
    const p2 = this.getPriority(t2)

    if (p1 == -1 && p2 == -1) return null
    if (p1 == -1) return t2
    if (p2 == -1) return t1

    return p1 <= p2 ? t1 : t2
  } 
  private fatherIndex(index: number): number {
    return Math.ceil(index / 2) - 1
  }
  private leftChildIndex(index: number): number {
    return 2 * index + 1
  }
  private rightChildIndex(index: number): number {
    return 2 * index + 2
  }

  printHeap() {
    console.log(this.heap)
  }

  enqueue(t: T): void {
    const len = this.heap.length
    this.heap.push(t)

    let currentIndex = len
    let fatherIndex = this.fatherIndex(currentIndex)
    while (
      this.getPriority(this.heap[fatherIndex]) > this.getPriority(this.heap[currentIndex])
    ) {
      if (fatherIndex == -1) break

      let aux = this.heap[fatherIndex]
      this.heap[fatherIndex] = this.heap[currentIndex]
      this.heap[currentIndex] = aux

      currentIndex = fatherIndex
      fatherIndex = this.fatherIndex(currentIndex)
    }
  }

  dequeue(): T {
    const dequeuedValue = this.heap[0]

    this.heap[0] = this.heap[this.heap.length - 1]
    let currentIndex = 0
    let currentLeftChildIndex = this.leftChildIndex(currentIndex)
    let currentRightChildIndex = this.rightChildIndex(currentIndex)
    let minChild = this.min(
      this.heap[currentLeftChildIndex], this.heap[currentRightChildIndex]
    )

    while (
      minChild &&
      this.getPriority(this.heap[currentIndex]) > this.getPriority(minChild)
    ) {
      if (minChild == this.heap[currentLeftChildIndex]) {
        let aux = this.heap[currentLeftChildIndex]
        this.heap[currentLeftChildIndex] = this.heap[currentIndex]
        this.heap[currentIndex] = aux

        currentIndex = currentLeftChildIndex
      } else {
        let aux = this.heap[currentRightChildIndex]
        this.heap[currentRightChildIndex] = this.heap[currentIndex]
        this.heap[currentIndex] = aux

        currentIndex = currentRightChildIndex
      }

      currentLeftChildIndex = this.leftChildIndex(currentIndex)
      currentRightChildIndex = this.rightChildIndex(currentIndex)

      minChild = this.min(
        this.heap[currentLeftChildIndex], this.heap[currentRightChildIndex]
      )
    }
    
    this.heap.pop()
    return dequeuedValue
  }
  
  getHeap(): T[] {
    return this.heap
  }
}

type Vertex = {
  id: string
  d: number
  pi?: Vertex
}

export class Graph {
  private V: Vertex[]
  private E: [Vertex, Vertex, number][]

  constructor(IDs: string[], E: [string, string, number][]) {
    this.V = IDs.map(id => ({ id, d: Infinity }))
    this.E = E.map(([indexV1, indexV2, weight]) => {
      const v1 = this.V.find((v) => v.id === indexV1)
      const v2 = this.V.find((v) => v.id === indexV2)

      if (!(v1 && v2))
        throw new Error("Wrong vertex indexes on graph initialization!")
      
      return [v1, v2, weight]
    })
  }

  private w(u: Vertex, v: Vertex): number {
    const i = this.E.findIndex(([v1, v2]) => v1.id == u.id && v2.id == v.id)
    if (i <= -1) return Infinity
    return this.E[i][2]
  }

  private adj(u: Vertex): Vertex[] {
    const adjs = this.E.filter(e => e[0].id == u.id)
    const v: Vertex[] = adjs.map(adj => this.V.find(v => v.id == adj[1].id)) as Vertex[]
    return v
  }

  private initializeSingleSource(s: Vertex): void {
    for (let i = 0; i < this.V.length; i++) {
      if (this.V[i].id === s.id) {
        this.V[i].d = 0
        continue
      }
      this.V[i].d = Infinity
      this.V[i].pi = undefined
    }
  }

  private relax(u: Vertex, v: Vertex) {
    if (v.d > u.d + this.w(u, v)) {
      v.d = u.d + this.w(u, v)
      v.pi = u
    }
  }

  printV() {
    const adaptedVs = this.V.map(v => ([v.id, v.d]))
    console.log(adaptedVs)
  }

  printE() {
    console.log(this.E)
  }

  dijkstra(indexSource: string) {
    const s = this.V.find((v) => v.id === indexSource)

    if (!s) throw new Error("Invalid source vertex ID on Dijkstra.")

    this.initializeSingleSource(s)

    const S: Vertex[] = []
    const Q = new MinHeapPriorityQueue<Vertex>((v => v.d), this.V)

    while (Q.getHeap().length > 0) {
      const u = Q.dequeue()
      S.push(u)
      this.adj(u).forEach(v => {
        this.relax(u, v)
      })
    }
  }
}

const cidadesBrasileiras = ["São Paulo",  "Rio de Janeiro",  "Belo Horizonte",  "Salvador",  "Fortaleza",  "Recife",  "Porto Alegre",  "Curitiba",  "Brasília",  "Manaus",  "Belém",  "Goiânia"];

const distanciasEntreCidades: [string, string, number][] = [["São Paulo", "Rio de Janeiro", 430],
  ["São Paulo", "Belo Horizonte", 586],
  ["São Paulo", "Brasília", 1016],
  ["Rio de Janeiro", "Salvador", 1223],
  ["Rio de Janeiro", "Fortaleza", 2663],
  ["Rio de Janeiro", "Porto Alegre", 1552],
  ["Belo Horizonte", "Recife", 1964],
  ["Belo Horizonte", "Curitiba", 1004],
  ["Salvador", "Manaus", 3781],
  ["Salvador", "Belém", 1997],
  ["Fortaleza", "Brasília", 2201],
  ["Recife", "Goiânia", 2058]
];

const grafo = new Graph(cidadesBrasileiras, distanciasEntreCidades)

console.log("Cidades conectadas: ")
grafo.printE()

console.log("Menores distâncias de São Paulo às outras cidades: ")
grafo.dijkstra("São Paulo")
grafo.printV()
