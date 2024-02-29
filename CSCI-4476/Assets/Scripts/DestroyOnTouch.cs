using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyOnTouch : MonoBehaviour, ITouchable
{
    public void OnStartTouch(){
        Destroy(gameObject);

    }
    public void OnKeepTouch(){}
    

  public void OnStopTouch(){}
}
