using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Renderer))]
[RequireComponent(typeof(Collider))]
public class ChangeColorOnTouch : MonoBehaviour, ITouchable
{
    [SerializeField] Color newColor = Color.white;
    Renderer ren;
    // Start is called before the first frame update
    void Awake()
    {
        ren = GetComponent<Renderer>();   
    }

    public void OnStartTouch(){
        ren.material.color = newColor;
    }

    public void OnKeepTouch(){

    }
    
    public void OnStopTouch(){

    }
}
