using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "New Pickup", menuName = "Pickups")]
public class PickupSO : ScriptableObject
{
    public enum PickupType {CURRENCY, ITEM, EQUIPMENT};
    public string objName;
    public PickupType type;
    public GameObject objModel;
    public AudioClip pickupSound;
    public AudioClip collisionSound;
}
