# Systems-Design

- Systems Design -
https://www.youtube.com/watch?v=bUHFg8CZFws
Groking the systems design interview

https://www.youtube.com/playlist?list=PLMCXHnjXnTnvo6alSjVkgxV-VH6EPyvoX
https://www.youtube.com/playlist?list=PLkQkbY7JNJuC99VDJcpQdww-4aT3QhdJv
https://www.youtube.com/playlist?list=PLkQkbY7JNJuAhePp7E_WSpfFqjQp6RniV
https://www.youtube.com/playlist?list=PLkQkbY7JNJuBoTemzQfjym0sqbOHt5fnV
https://www.youtube.com/playlist?list=PLA8lYuzFlBqAy6dkZHj5VxUAaqr4vwrka
https://www.youtube.com/playlist?list=PLhgw50vUymycJPN6ZbGTpVKAJ0cL4OEH3

### Gateway
Lo utilizo cuando tengo multiples micro-servicios, así sabe directamente a cual redireccionar la request  y en caso de falla no tengo un Single Point of Failure.

### Load Balancer
Es una maquina que actua como reverse proxy
Para cada request elige uno de los servidores segun su estrategia (round robin)
Hace que el sistema sea mas escalable y resiliente
Lo uso cuando necesito enviar las Request de forma uniforme a los distintos servidores, luego de realizar un horizontal scaling.

### CDN (Content Delivery Network)
**Definición:** A content delivery network, or content distribution network (CDN), is a geographically distributed network of proxy servers and their data centers. The goal is to provide high availability and performance by distributing the service spatially relative to end users.

- Ventajas
Permite tener las imagenes staticas cerca de los usuarios
Reduce costos
Reduce latencia

- Desventajas
Aumenta complejidad del sistema

Más información: https://www.cloudflare.com/learning/cdn/what-is-a-cdn/


### Cache / Redis (Global Cache)
**Ventajas:**
- Reduce/Save network calls
- Avoid repeated computations 
- Reduce DB load (aka throughput)
- mejora la performance de lectura (aka latency)

Desvantajas:
- Añade complejidad
- Consume recursos

**Tipos:**
- *Write Through* (primero hitea al cache y luego lo pasa a la BD), Se usa cuando trabajo con critical data (financial, etc).
- *Write Behind* 
- Hybrido + Puedo utilizar un sistema de Bulk y así lograr reducir las llamadas para escribir a la BD
- *Cache Aside*
- *Read through*

**Policy:**
- Podemos utilizar LRU (más popular), LFU u otra política para decidir que información mantener en el Cache.



### Message Queue
Lo utilizo para mantener un orden en las Request y atender siempre a la que llega primero (FIFO).

### Session service
Puedo manejar el tema del login, así no se verifica y se ejecuta el código relacionado a la autenticación por todos lados.

### Auth service

### Heartbeats (Health Service)
Nos permite saber si el servicio que estamos utilizando sigue estable (no se murió en el medio de una transacción), de esta forma nos permite re-asignar la tarea a otro servidor horizontal.

### Protocols
- **HTTP Protocol (Client - Server)**
- **Long Polling / Ajax Polling** - Pull

- **XMPP** (Chat) + Websocket
- Web Socket or TCP (My own protocol)** - Push
- Peer-Peer Protocol (Everyone is equal, both sides are machines)

### Consistent Hashing
Lo utilizo cuando necesito añadir y remover datos, así puedo localizarlo mismo si agrego nuevos servidores

### SQL vs NoSQL
**SQL**
- Relational databases store data in rows and columns. Each row contains all the information about one entity and each column contains all the separate data points. Some of the most popular relational databases are MySQL, Oracle, MS SQL Server, SQLite, Postgres, and MariaDB.

**NoSQL** Cassandra (wide-column) / Dynamo (key-value stores)
- Key-Value Stores: Data is stored in an array of key-value pairs. The ‘key’ is an attribute name which is linked to a ‘value’. Well-known key-value stores include Redis, Voldemort, and Dynamo.

- Wide-Column Databases: Instead of ‘tables,’ in columnar databases we have column families, which are containers for rows. Unlike relational databases, we don’t need to know all the columns up front and each row doesn’t have to have the same number of columns. Columnar databases are best suited for analyzing large datasets - big names include Cassandra and HBase.

**Scalability**: In most common situations, SQL databases are vertically scalable, i.e., by increasing the horsepower (higher Memory, CPU, etc.) of the hardware, which can get very expensive. It is possible to scale a relational database across multiple servers, but this is a challenging and time-consuming process. 
On the other hand, NoSQL databases are horizontally scalable, meaning we can add more servers easily in our NoSQL database infrastructure to handle a lot of traffic. Any cheap commodity hardware or cloud instances can host NoSQL databases, thus making it a lot more cost-effective than vertical scaling. A lot of NoSQL technologies also distribute data across servers automatically.

**Otras ventajas de una BD NoSQL**
- Insertions and Retrievals
- Schema is easily changeable
- Built for scale
- Built for metrics/analytics/aggregations

**Otras desventajas**
- Not built for Updates
- ACID not guaranteed
- Read times are slower than SQL
- Relations are not explicit (No existe Foreign Key)
- Joins are hard

### Data Sharding / Data Partitioning
Data partitioning is a technique to break up a big database (DB) into many smaller parts. It is the process of splitting up a DB/table across multiple machines to improve the manageability, performance, availability, and load balancing of an application. The justification for data partitioning is that, after a certain scale point, it is cheaper and more feasible to scale horizontally by adding more machines than to grow it vertically by adding beefier servers.

*Obs:* Si necesito las condiciones de una BD NoSQL en una SQL, debo utilizar Sharding -> Horizontal Partitioning 

- Horizontal Partitioning
Utilizo el Horizontal Partitioning cuando tengo varios atributos por los que deseo filtrar (multiples indexes, una tabla debería tener un único index, por eso se utiliza el Horitozntal Partitioning),

### Master-Slave architecture
 Para evitar el Single Point of Failure se utiliza la arquitectura Master-Slave, en donde si falla el Master se utiliza el "backup" del Slave. 


### Photos / Image Service
- **File** vs **Blob** (Binary Long Object)

### Post Notify
- Pocos followers: push
- Muchos followers: pull (así evitamos que se tranque todo haciendo millones de pushs cuando un famoso publica algo)

Estas son las cosas que la BD nos da si queremos utilizarla para guardar las fotos como Blobs
- 1) Mutability
- 2) ACID
- 3) Indexes
- 4) Access Control

Por lo tanto, casi siempre rinde más guardar las imagenes como Files utilizando un **File System** ya que son archivos completamente nuevos y distintos del que queremos eliminar.

*Ventajas de utilizar File System:*
- 1) Cheaper
- 2) Faster
- 3) Control Delivery Network

### Single Point of Failure
1) Client 
2) DNS (ips para saber a cual gateway conectarse)
3) Gateway (Load Balancer)
4) Add more Nodes (Servers)
5) Master-Slave (BD)
6) Multiple Regions

### Publish / Subscriber
**Message Broker** (PUEDE GENERAR INCONSISTENCIA, CUIDADO!)
- Al utilizar un message broker me aseguro que varios puntos reciben la información a la vez y luego informo el resultado al cliente.
- Al utilizarlo me añade desacoplamiento ya que pasa mensajes genéricos a las demás capas internas / servicios y estos se encargan de utilizar sólo la información necesaria.
- Añade escalabilidad

### MONOLITH vs MICROSERVICES
En sistemas grandes siempre es mejor utilizar microsistemas.

Que es una arquitectura de microsistemas?

Que es una arquitectura monolith?
