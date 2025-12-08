# UnrealShadows_LOTL

#1. Understanding Actor relevancy
Replication Properties：
bAlwaysRelevant: Forces the Actor to always be "relevant" to all clients (ignoring distance/visibility, use with caution!)
bNetUseOwnerRelevancy: Inherit the owner's relevancy (for example, a player's weapon will be synchronized to where the player is)
bOnlyRelevantToOwner: Only "relevant" to the owner client (for example, the player's private backpack, which is invisible to other clients)
bHidden: Whether the Actor is hidden (when hidden and without collision, it is not synchronized by default)
net cull distance Network: culling distance (Actors beyond this distance are directly judged as irrelevant, which can be adjusted in the project settings)

#2. Understanding property replication:
Enabling property replication:
```c++
UPROPERTY(Replicated)
int32 Score;
```
If you are in need of a callback function to be executed when a property is updated, you can use
ReplicatedUsing=[FunctionName] instead :
```c++
UPROPERTY(ReplicatedUsing="OnRep_Score")
int32 Score;
```
After that, you need to override function:
```c++
virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
```
You can use three Macros to implement `GetLifetimeReplicatedProps` :
```c++
DOREPLIFETIME(class name, property name): Basic macro, which synchronizes properties unconditionally (server → all clients)
```
```c++
DOREPLIFETIME_CONDITION(class name, property name, condition): Conditional replication (such as replicating only to the owner, only to the simulation side, etc.);
```
```c++
DOREPLIFETIME_ACTIVE_OVERRIDE(): Fully custom synchronization logic (determine whether to synchronize through a function within the Actor).
```
