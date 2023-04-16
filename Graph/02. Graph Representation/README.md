### Ways to represent the Graph :
- Adjacency Matrix
 <img src="https://user-images.githubusercontent.com/33116849/229985612-bbbe5e94-2f99-4291-8dec-0a862191deff.png" width="200"/>
 
```
To create adjacency matrix , we need 2-d array but here time complexity would be n^2,
so better approach is represent the graph using adjacency list
```

- Adjacency List
 <img src="https://user-images.githubusercontent.com/33116849/229984818-64ccd6b1-374d-4b98-a311-9ee3816f33b2.png" width="200"/>

 ```
    To create the adjacency list we have to create an array of vectors of size n (where n = number of nodes)

    > vector<int> adj[n] { that's how we create array of vectors in c++ }

    for above graph , adjacency list will look like :

    1-> {2,3}
    2-> {1,4}
    3-> {1,4,5}
    4-> {3,2,5}
    5-> {3,4}
    
    Space Complexity : 2 * E { here every edge we are counting twice }
  ```
  
