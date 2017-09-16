package com.example.starcluster.myapplication;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Toast;

public class ToastActivity extends AppCompatActivity
{
    private Button defaultEffect,setLocationEffect,imageEffect,setLocationImageEffect,returnMainActivity;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_toast);

        defaultEffect = (Button)findViewById(R.id.defaultEffect);
        setLocationEffect = (Button)findViewById(R.id.setLocationEffect);
        imageEffect = (Button)findViewById(R.id.imageEffect);
        setLocationImageEffect = (Button)findViewById(R.id.setLocationImageEffect);
        returnMainActivity = (Button)findViewById(R.id.returnMainActivity);
    }

    public void onClick_Event(View v)
    {
        Toast toast;
        LinearLayout toastView;
        ImageView imageCodeProject;
        switch (v.getId())
        {
            case R.id.defaultEffect:
                Toast.makeText(ToastActivity.this,"这是默认的toast效果",Toast.LENGTH_SHORT).show();
                break;
            case R.id.setLocationEffect:
                toast = Toast.makeText(ToastActivity.this,"这是自定义位置的toast效果.",Toast.LENGTH_SHORT);
                toast.setGravity(Gravity.CENTER,0,0);
                toast.show();
                break;
            case R.id.imageEffect:
                toast = Toast.makeText(ToastActivity.this,"这是带图片的Toast效果", Toast.LENGTH_SHORT);
                toastView = (LinearLayout) toast.getView();
                imageCodeProject = new ImageView(getApplicationContext());
                imageCodeProject.setImageResource(R.mipmap.ic_launcher);
                toastView.addView(imageCodeProject, 0);
                toast.show();
                break;
            case R.id.setLocationImageEffect:
                toast = Toast.makeText(ToastActivity.this,"这是自定义位置的带图片的Toast效果", Toast.LENGTH_SHORT);
                toast.setGravity(Gravity.CENTER, 0, 0);
                toastView = (LinearLayout) toast.getView();
                imageCodeProject = new ImageView(getApplicationContext());
                imageCodeProject.setImageResource(R.drawable.test);
                toastView.addView(imageCodeProject, 0);
                toast.show();
                break;
            case R.id.returnMainActivity:
                ToastActivity.this.finish();
                break;
        }
    }
}// end of class
