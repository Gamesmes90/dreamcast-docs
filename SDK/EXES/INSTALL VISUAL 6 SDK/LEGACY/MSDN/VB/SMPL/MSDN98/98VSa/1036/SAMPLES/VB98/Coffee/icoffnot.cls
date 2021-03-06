VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "ICoffeeNotify"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

' Le module ICoffeeNotify d�finie une interface
'   contenant la m�thode de rappel CoffeeReady,
'   et une propri�t� utilis�e pour stocker l'ID
'   du client (affect� par CoffeeMonitor2).
'

' L'impl�mentation de la m�thode CoffeeReady contient
' ----------- tout le code que le client veut
'   ex�cuter lorsqu'un rappel se produit.
'
Public Sub CoffeeReady()
End Sub

' L'impl�mentation de la propri�t� NotifyID doit fournir 
' --------    des donn�es de type Long pour stocker
'   le num�ro ID. CoffeeMonitor2 l'utilise pour
'   rechercher l'objet de rappel lorsque une
'   demande de d�connexion est faite.
'
Public Property Get NotifyID() As Long
End Property
Public Property Let NotifyID(ByVal NewValue As Long)
End Property
