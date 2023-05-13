class Queue<T> {
  private items: T[]

  constructor(values?: T[]) {
    this.items = []

    if (values)
      this.items = values
  }

  enqueue(item: T): void {
    this.items.push(item)
  }

  dequeue(): T | undefined {
    return this.items.shift()
  }

  isEmpty(): boolean {
    return this.items.length === 0
  }

  size(): number {
    return this.items.length
  }
}

type Vertex = {
  id: string
  color: "w" | "g" | "b"
  d?: number
  pi?: Vertex
}

class Graph {
  private V: Vertex[]
  private E: [Vertex, Vertex[]][]

  private adj(u: Vertex): Vertex[] {
    const tupleFound = this.E.find(([v, list]) => v.id == u.id)
    if (!tupleFound) throw new Error("No vertex found with id " + u.id + ".")
    return tupleFound[1]
  }

  constructor(e: [string, string[]][]) {
    this.V = e.map(([id]) => ({ id, color: "w" }))
    this.E = e.map(
      ([vId, list]) => [{ id: vId, color: "w" }, list.map(v => ({ id: v, color: "w" }))]
    )
  }

  DFS(vId: string): void {
    const s = this.V.find(v => v.id === vId)
    if (!s) throw new Error("Source vertex not found!")
    
    this.V.forEach(v => {
      v.color = "w"
      v.d = Infinity
    })
    
    s.color = "g"
    s.d = 0
    const Q = new Queue<Vertex>()
    Q.enqueue(s)
    while (!Q.isEmpty()) {
      const u = Q.dequeue() as Vertex
      this.adj(u).forEach(v => {
        if (v.color === "w") {
          v.color = "g"
          v.d = u.d as number + 1
          v.pi = u
          Q.enqueue(v)
        }
      })
      u.color = "b"
    }
  }

  printD() {
    this.V.forEach(v => {
      const tuple = [v.id, v.d]
      console.log(tuple)
    })
  }
}

const personRelations: [string, string[]][] = [
  ["Alice", ["Bob", "Charlie", "David"]],
  ["Bob", ["Alice", "Charlie"]],
  ["Charlie", ["Alice", "Bob", "David"]],
  ["David", ["Alice", "Charlie"]],
];

const G = new Graph(personRelations)

G.DFS("Alice")

G.printD()
