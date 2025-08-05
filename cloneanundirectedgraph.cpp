Node* cloneGraph(Node* node) {
        // code here
       
        if(!node)
        return NULL;
        map<Node*,Node*>mp;
        queue<Node*>q;
        Node* clone=new Node();
        
        clone->val=node->val;
        mp[node]=clone;
        q.push(node);
        
        while(!q.empty())
        {
            Node* u=q.front();
            q.pop();
            
            for(auto& neighbor:u->neighbors)
            {
                if(mp.find(neighbor)==mp.end())
                {
                    Node* neighborClone=new Node();
                    neighborClone->val=neighbor->val;
                    mp[neighbor]=neighborClone;
                    q.push(neighbor);
                }
                mp[u]->neighbors.push_back(mp[neighbor]);
            }
        }
        return mp[node];

    }
