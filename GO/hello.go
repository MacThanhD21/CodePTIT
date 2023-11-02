package main

import (
	"container/list"
	"fmt"
)

// Định nghĩa đồ thị bằng danh sách liên kết
type Graph struct {
	nodes int
	adj   map[int][]int
}

// Hàm khởi tạo đồ thị
func NewGraph(nodes int) *Graph {
	graph := &Graph{
		nodes: nodes,
		adj:   make(map[int][]int),
	}
	return graph
}

// Hàm thêm cạnh vào đồ thị
func (g *Graph) AddEdge(u, v int) {
	g.adj[u] = append(g.adj[u], v)
}

// Hàm duyệt đồ thị bằng BFS
func (g *Graph) BFS(start int) {
	visited := make(map[int]bool)
	queue := list.New()

	visited[start] = true
	queue.PushBack(start)

	for queue.Len() > 0 {
		node := queue.Front()
		fmt.Printf("%d ", node.Value)
		queue.Remove(node)
		adjNodes, _ := g.adj[node.Value.(int)]
		for _, n := range adjNodes {
			if !visited[n] {
				visited[n] = true
				queue.PushBack(n)
			}
		}
	}
}

func main() {
	graph := NewGraph(6)
	graph.AddEdge(0, 1)
	graph.AddEdge(0, 2)
	graph.AddEdge(1, 3)
	graph.AddEdge(2, 4)
	graph.AddEdge(2, 5)
	graph.AddEdge(2, 8)

	fmt.Println("BFS Traversal starting from vertex 0:")
	graph.BFS(0)
}